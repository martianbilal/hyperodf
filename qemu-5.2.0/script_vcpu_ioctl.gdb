b load_snapshot_memory
commands 
    printf "[gdb] starting the load snapshot\n"
    b kvm_vcpu_ioctl
    commands
        printf "[gdb] called kvm_vcpu_ioctl\n"
        bt
        c
    end
    b kvm_vm_ioctl
    commands
        printf "[gdb] called kvm_vm_ioctl\n"
        bt
        c
    end
    b kvm_cpu_exec
    commands
        printf "[gdb] called kvm_cpu_exec\n"
        bt
        d 0
        d 1
        d 2
        d 3
        c
    end
    c
end

r