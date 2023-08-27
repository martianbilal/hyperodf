/*
 * QEMU Management Protocol commands
 *
 * Copyright IBM, Corp. 2011
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 *
 * Contributions after 2012-01-13 are licensed under the terms of the
 * GNU GPL, version 2 or (at your option) any later version.
 */

#include "qemu/osdep.h"
#include "qemu-common.h"
#include "qemu/cutils.h"
#include "qemu/option.h"
#include "monitor/monitor.h"
#include "qemu/typedefs.h"
#include "sysemu/sysemu.h"
#include "qemu/config-file.h"
#include "qemu/uuid.h"
#include "chardev/char.h"
#include "ui/qemu-spice.h"
#include "ui/vnc.h"
#include "sysemu/kvm.h"
#include "sysemu/runstate.h"
#include "sysemu/arch_init.h"
#include "sysemu/blockdev.h"
#include "sysemu/block-backend.h"
#include "qapi/error.h"
#include "qapi/qapi-commands-acpi.h"
#include "qapi/qapi-commands-block.h"
#include "qapi/qapi-commands-control.h"
#include "qapi/qapi-commands-machine.h"
#include "qapi/qapi-commands-misc.h"
#include "qapi/qapi-commands-ui.h"
#include "qapi/qmp/qerror.h"
#include "hw/mem/memory-device.h"
#include "hw/acpi/acpi_dev_interface.h"
#include "migration/snapshot.h"
#include "util/forkall-coop.h"
#include "util/hodf-util.h"
#include "qemu/main-loop.h"



HelloResult *qmp_get_hello(Error **errp)
{
    HelloResult *res = g_malloc0(sizeof(*res));
    res->greeting = g_strdup("Hello from QEMU!");
    return res;
}

static void del_vm(const char* name, Error **errp){
    BlockDriverState *bs;
    if (bdrv_all_delete_snapshot(name, &bs, errp) < 0) {
        error_prepend(errp,
                      "deleting snapshot on device '%s': ",
                      bdrv_get_device_name(bs));
    }
}

static void save_vm(const char* name, Error **errp){
    save_snapshot(name, errp);
    printf("save_vm[%s]\n", name);
}

static void load_vm(const char* name, Error **errp){
    load_snapshot(name, errp);

    // signal completion of load_snapshot
    h_signal_child_done();

    printf("load_vm[%s]\n", name);
}

static int create_socket(const char *path){
    int sock;
    if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    return sock;
}

static void configure_server(struct sockaddr_un *server_addr, const char *path) {
    memset(server_addr, 0, sizeof(*server_addr));
    server_addr->sun_family = AF_UNIX;
    strncpy(server_addr->sun_path, path, sizeof(server_addr->sun_path) - 1);
    // Remove old socket file if it exists
    unlink(path);
}

// bind and listen to the socket
static void start_socket(const char *path){
    int server_sock = create_socket(path);
    
    printf("server-sock : %d\n", server_sock);

    struct sockaddr_un server_addr;
    configure_server(&server_addr, path);

    // Bind the socket to the server address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_un client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock;

    if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len)) == -1) {
        perror("accept");
    }


    // dup2(client_sock, 30); --> old hacky way
    // dup2(client_sock, h_get_monitor_fd() + 1);  // new way
    dup2(server_sock, 16);  // hacky for changing server side stuff
    close(client_sock);

}

static void create_mon_new(void){
    start_socket("child-qmp.sock");
}

static pid_t do_ski_fork(void){
    pid_t pid = 0;
    int locked = qemu_mutex_iothread_locked();

    kick_all();
    if(locked) qemu_mutex_unlock_iothread();

    pid = ski_forkall_master();
    if(locked) qemu_mutex_lock_iothread();

    if(pid == 0){
        // child
        printf("I am child\n");
        create_mon_new();
        forkall_child_wait();
        return pid;
    } else if(pid > 0) {
        // parent
        printf("I am parent\n");
        h_wait_for_load_snapshot();
        return pid;
    } else {
        // error
        printf("fork error\n");
        exit(-1);
    }

    return pid;
}

forkResult *qmp_vm_fork(Error **errp){
    int pid = 0;
    const char *name = "newtest";   // can get this name from user in future
    forkResult *res = g_malloc0(sizeof(*res));
    
    // delete snapshot 
    del_vm(name, errp);

    // save vm
    save_vm(name, errp);

    // do fork
    pid = do_ski_fork();
    
    // only load in child
    if(forkall_check_child()){
        load_vm(name, errp);
    }


    // only send pid in parent
    if(pid) res->childpid = pid;

    // child gets pid == 0
    return res;
}

NameInfo *qmp_query_name(Error **errp)
{
    NameInfo *info = g_malloc0(sizeof(*info));

    if (qemu_name) {
        info->has_name = true;
        info->name = g_strdup(qemu_name);
    }

    return info;
}

KvmInfo *qmp_query_kvm(Error **errp)
{
    KvmInfo *info = g_malloc0(sizeof(*info));

    info->enabled = kvm_enabled();
    info->present = kvm_available();

    return info;
}

UuidInfo *qmp_query_uuid(Error **errp)
{
    UuidInfo *info = g_malloc0(sizeof(*info));

    info->UUID = qemu_uuid_unparse_strdup(&qemu_uuid);
    return info;
}

void qmp_quit(Error **errp)
{
    no_shutdown = 0;
    qemu_system_shutdown_request(SHUTDOWN_CAUSE_HOST_QMP_QUIT);
}

void qmp_stop(Error **errp)
{
    /* if there is a dump in background, we should wait until the dump
     * finished */
    if (dump_in_progress()) {
        error_setg(errp, "There is a dump in process, please wait.");
        return;
    }

    if (runstate_check(RUN_STATE_INMIGRATE)) {
        autostart = 0;
    } else {
        vm_stop(RUN_STATE_PAUSED);
    }
}

void qmp_system_reset(Error **errp)
{
    qemu_system_reset_request(SHUTDOWN_CAUSE_HOST_QMP_SYSTEM_RESET);
}

void qmp_system_powerdown(Error **errp)
{
    qemu_system_powerdown_request();
}

void qmp_x_exit_preconfig(Error **errp)
{
    if (!runstate_check(RUN_STATE_PRECONFIG)) {
        error_setg(errp, "The command is permitted only in '%s' state",
                   RunState_str(RUN_STATE_PRECONFIG));
        return;
    }
    qemu_exit_preconfig_request();
}

void qmp_cont(Error **errp)
{
    BlockBackend *blk;
    BlockJob *job;
    Error *local_err = NULL;

    /* if there is a dump in background, we should wait until the dump
     * finished */
    if (dump_in_progress()) {
        error_setg(errp, "There is a dump in process, please wait.");
        return;
    }

    if (runstate_needs_reset()) {
        error_setg(errp, "Resetting the Virtual Machine is required");
        return;
    } else if (runstate_check(RUN_STATE_SUSPENDED)) {
        return;
    } else if (runstate_check(RUN_STATE_FINISH_MIGRATE)) {
        error_setg(errp, "Migration is not finalized yet");
        return;
    }

    for (blk = blk_next(NULL); blk; blk = blk_next(blk)) {
        blk_iostatus_reset(blk);
    }

    for (job = block_job_next(NULL); job; job = block_job_next(job)) {
        block_job_iostatus_reset(job);
    }

    /* Continuing after completed migration. Images have been inactivated to
     * allow the destination to take control. Need to get control back now.
     *
     * If there are no inactive block nodes (e.g. because the VM was just
     * paused rather than completing a migration), bdrv_inactivate_all() simply
     * doesn't do anything. */
    bdrv_invalidate_cache_all(&local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }

    if (runstate_check(RUN_STATE_INMIGRATE)) {
        autostart = 1;
    } else {
        vm_start();
    }
}

void qmp_system_wakeup(Error **errp)
{
    if (!qemu_wakeup_suspend_enabled()) {
        error_setg(errp,
                   "wake-up from suspend is not supported by this guest");
        return;
    }

    qemu_system_wakeup_request(QEMU_WAKEUP_REASON_OTHER, errp);
}

void qmp_set_password(const char *protocol, const char *password,
                      bool has_connected, const char *connected, Error **errp)
{
    int disconnect_if_connected = 0;
    int fail_if_connected = 0;
    int rc;

    if (has_connected) {
        if (strcmp(connected, "fail") == 0) {
            fail_if_connected = 1;
        } else if (strcmp(connected, "disconnect") == 0) {
            disconnect_if_connected = 1;
        } else if (strcmp(connected, "keep") == 0) {
            /* nothing */
        } else {
            error_setg(errp, QERR_INVALID_PARAMETER, "connected");
            return;
        }
    }

    if (strcmp(protocol, "spice") == 0) {
        if (!qemu_using_spice(errp)) {
            return;
        }
        rc = qemu_spice.set_passwd(password, fail_if_connected,
                                   disconnect_if_connected);
        if (rc != 0) {
            error_setg(errp, QERR_SET_PASSWD_FAILED);
        }
        return;
    }

    if (strcmp(protocol, "vnc") == 0) {
        if (fail_if_connected || disconnect_if_connected) {
            /* vnc supports "connected=keep" only */
            error_setg(errp, QERR_INVALID_PARAMETER, "connected");
            return;
        }
        /* Note that setting an empty password will not disable login through
         * this interface. */
        rc = vnc_display_password(NULL, password);
        if (rc < 0) {
            error_setg(errp, QERR_SET_PASSWD_FAILED);
        }
        return;
    }

    error_setg(errp, QERR_INVALID_PARAMETER, "protocol");
}

void qmp_expire_password(const char *protocol, const char *whenstr,
                         Error **errp)
{
    time_t when;
    int rc;

    if (strcmp(whenstr, "now") == 0) {
        when = 0;
    } else if (strcmp(whenstr, "never") == 0) {
        when = TIME_MAX;
    } else if (whenstr[0] == '+') {
        when = time(NULL) + strtoull(whenstr+1, NULL, 10);
    } else {
        when = strtoull(whenstr, NULL, 10);
    }

    if (strcmp(protocol, "spice") == 0) {
        if (!qemu_using_spice(errp)) {
            return;
        }
        rc = qemu_spice.set_pw_expire(when);
        if (rc != 0) {
            error_setg(errp, QERR_SET_PASSWD_FAILED);
        }
        return;
    }

    if (strcmp(protocol, "vnc") == 0) {
        rc = vnc_display_pw_expire(NULL, when);
        if (rc != 0) {
            error_setg(errp, QERR_SET_PASSWD_FAILED);
        }
        return;
    }

    error_setg(errp, QERR_INVALID_PARAMETER, "protocol");
}

#ifdef CONFIG_VNC
void qmp_change_vnc_password(const char *password, Error **errp)
{
    if (vnc_display_password(NULL, password) < 0) {
        error_setg(errp, QERR_SET_PASSWD_FAILED);
    }
}

static void qmp_change_vnc_listen(const char *target, Error **errp)
{
    QemuOptsList *olist = qemu_find_opts("vnc");
    QemuOpts *opts;

    if (strstr(target, "id=")) {
        error_setg(errp, "id not supported");
        return;
    }

    opts = qemu_opts_find(olist, "default");
    if (opts) {
        qemu_opts_del(opts);
    }
    opts = vnc_parse(target, errp);
    if (!opts) {
        return;
    }

    vnc_display_open("default", errp);
}

static void qmp_change_vnc(const char *target, bool has_arg, const char *arg,
                           Error **errp)
{
    if (strcmp(target, "passwd") == 0 || strcmp(target, "password") == 0) {
        if (!has_arg) {
            error_setg(errp, QERR_MISSING_PARAMETER, "password");
        } else {
            qmp_change_vnc_password(arg, errp);
        }
    } else {
        qmp_change_vnc_listen(target, errp);
    }
}
#endif /* !CONFIG_VNC */

void qmp_change(const char *device, const char *target,
                bool has_arg, const char *arg, Error **errp)
{
    if (strcmp(device, "vnc") == 0) {
#ifdef CONFIG_VNC
        qmp_change_vnc(target, has_arg, arg, errp);
#else
        error_setg(errp, QERR_FEATURE_DISABLED, "vnc");
#endif
    } else {
        qmp_blockdev_change_medium(true, device, false, NULL, target,
                                   has_arg, arg, false, 0, errp);
    }
}

void qmp_add_client(const char *protocol, const char *fdname,
                    bool has_skipauth, bool skipauth, bool has_tls, bool tls,
                    Error **errp)
{
    Chardev *s;
    int fd;

    fd = monitor_get_fd(monitor_cur(), fdname, errp);
    if (fd < 0) {
        return;
    }

    if (strcmp(protocol, "spice") == 0) {
        if (!qemu_using_spice(errp)) {
            close(fd);
            return;
        }
        skipauth = has_skipauth ? skipauth : false;
        tls = has_tls ? tls : false;
        if (qemu_spice.display_add_client(fd, skipauth, tls) < 0) {
            error_setg(errp, "spice failed to add client");
            close(fd);
        }
        return;
#ifdef CONFIG_VNC
    } else if (strcmp(protocol, "vnc") == 0) {
        skipauth = has_skipauth ? skipauth : false;
        vnc_display_add_client(NULL, fd, skipauth);
        return;
#endif
    } else if ((s = qemu_chr_find(protocol)) != NULL) {
        if (qemu_chr_add_client(s, fd) < 0) {
            error_setg(errp, "failed to add client");
            close(fd);
            return;
        }
        return;
    }

    error_setg(errp, "protocol '%s' is invalid", protocol);
    close(fd);
}


MemoryDeviceInfoList *qmp_query_memory_devices(Error **errp)
{
    return qmp_memory_device_list();
}

ACPIOSTInfoList *qmp_query_acpi_ospm_status(Error **errp)
{
    bool ambig;
    ACPIOSTInfoList *head = NULL;
    ACPIOSTInfoList **prev = &head;
    Object *obj = object_resolve_path_type("", TYPE_ACPI_DEVICE_IF, &ambig);

    if (obj) {
        AcpiDeviceIfClass *adevc = ACPI_DEVICE_IF_GET_CLASS(obj);
        AcpiDeviceIf *adev = ACPI_DEVICE_IF(obj);

        adevc->ospm_status(adev, &prev);
    } else {
        error_setg(errp, "command is not supported, missing ACPI device");
    }

    return head;
}

MemoryInfo *qmp_query_memory_size_summary(Error **errp)
{
    MemoryInfo *mem_info = g_malloc0(sizeof(MemoryInfo));

    mem_info->base_memory = ram_size;

    mem_info->plugged_memory = get_plugged_memory_size();
    mem_info->has_plugged_memory =
        mem_info->plugged_memory != (uint64_t)-1;

    return mem_info;
}
