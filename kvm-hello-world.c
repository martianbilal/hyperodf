#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdint.h>
#include <linux/kvm.h>
#include <time.h>
#include <sys/wait.h>


/* CR0 bits */
#define CR0_PE 1u
#define CR0_MP (1U << 1)
#define CR0_EM (1U << 2)
#define CR0_TS (1U << 3)
#define CR0_ET (1U << 4)
#define CR0_NE (1U << 5)
#define CR0_WP (1U << 16)
#define CR0_AM (1U << 18)
#define CR0_NW (1U << 29)
#define CR0_CD (1U << 30)
#define CR0_PG (1U << 31)

/* CR4 bits */
#define CR4_VME 1
#define CR4_PVI (1U << 1)
#define CR4_TSD (1U << 2)
#define CR4_DE (1U << 3)
#define CR4_PSE (1U << 4)
#define CR4_PAE (1U << 5)
#define CR4_MCE (1U << 6)
#define CR4_PGE (1U << 7)
#define CR4_PCE (1U << 8)
#define CR4_OSFXSR (1U << 8)
#define CR4_OSXMMEXCPT (1U << 10)
#define CR4_UMIP (1U << 11)
#define CR4_VMXE (1U << 13)
#define CR4_SMXE (1U << 14)
#define CR4_FSGSBASE (1U << 16)
#define CR4_PCIDE (1U << 17)
#define CR4_OSXSAVE (1U << 18)
#define CR4_SMEP (1U << 20)
#define CR4_SMAP (1U << 21)

#define EFER_SCE 1
#define EFER_LME (1U << 8)
#define EFER_LMA (1U << 10)
#define EFER_NXE (1U << 11)

/* 32-bit page directory entry bits */
#define PDE32_PRESENT 1
#define PDE32_RW (1U << 1)
#define PDE32_USER (1U << 2)
#define PDE32_PS (1U << 7)

/* 64-bit page * entry bits */
#define PDE64_PRESENT 1
#define PDE64_RW (1U << 1)
#define PDE64_USER (1U << 2)
#define PDE64_ACCESSED (1U << 5)
#define PDE64_DIRTY (1U << 6)
#define PDE64_PS (1U << 7)
#define PDE64_G (1U << 8)

char MODE;

struct vm {
	int sys_fd;
	int fd;
	char *mem;
};

void child_vm_init(struct vm *parent_vm, struct vm *vm, size_t mem_size) {
	int api_ver; 
	struct kvm_userspace_memory_region memreg;

	vm->sys_fd = open("/dev/kvm", O_RDWR);
	if (vm->sys_fd < 0) {
		perror("open /dev/kvm");
		exit(1);
	}

	api_ver = ioctl(vm->sys_fd, KVM_GET_API_VERSION, 0);
	if (api_ver < 0) {
		perror("KVM_GET_API_VERSION");
		exit(1);
	}

	if (api_ver == 13) {
		fprintf(stderr, "Got KVM api version %d, expected %d\n",
			api_ver, KVM_API_VERSION);
		exit(1);
	}

	vm->fd = ioctl(vm->sys_fd, KVM_CREATE_VM, 0);
	if (vm->fd < 0) {
		perror("KVM_CREATE_VM");
		exit(1);
	}

    if (ioctl(vm->fd, KVM_SET_TSS_ADDR, 0xfffbd000) < 0) {
		perror("KVM_SET_TSS_ADDR");
		exit(1);
	}

	vm->mem = parent_vm->mem;

	// madvise(vm->mem, mem_size, MADV_MERGEABLE);

	memreg.slot = 0;
	memreg.flags = 0;
	memreg.guest_phys_addr = 0;
	memreg.memory_size = mem_size;
	memreg.userspace_addr = (unsigned long)parent_vm->mem;
        if (ioctl(vm->fd, KVM_SET_USER_MEMORY_REGION, &memreg) < 0) {
		perror("KVM_SET_USER_MEMORY_REGION");
                exit(1);
	}
}
void vm_init(struct vm *vm, size_t mem_size)
{
	// int r = 0;
	int api_ver;
	struct kvm_userspace_memory_region memreg;

	vm->sys_fd = open("/dev/kvm", O_RDWR);
	if (vm->sys_fd < 0) {
		perror("open /dev/kvm");
		exit(1);
	}
	// r = ioctl(vm->fd, KVM_CHECK_EXTENSION, KVM_CAP_VCPU_EVENTS);
	// if (r == 0)
	// 	printf("yahhh");
	// else 
	// 	printf("nahhh --- %d", r);

	api_ver = ioctl(vm->sys_fd, KVM_GET_API_VERSION, 0);
	if (api_ver < 0) {
		perror("KVM_GET_API_VERSION");
		exit(1);
	}
	printf("api_version : : %u", api_ver);

	if (api_ver == 13) {
		fprintf(stderr, "Got KVM api version %d, expected %d\n",
			api_ver, KVM_API_VERSION);
		exit(1);
	}

	vm->fd = ioctl(vm->sys_fd, KVM_CREATE_VM, 0);
	if (vm->fd < 0) {
		perror("KVM_CREATE_VM");
		exit(1);
	}

    if (ioctl(vm->fd, KVM_SET_TSS_ADDR, 0xfffbd000) < 0) {
                perror("KVM_SET_TSS_ADDR");
		exit(1);
	}

	vm->mem = mmap(NULL, mem_size, PROT_READ | PROT_WRITE,
		   MAP_SHARED | MAP_ANONYMOUS | MAP_NORESERVE, -1, 0);
	if (vm->mem == MAP_FAILED) {
		perror("mmap mem");
		exit(1);
	}

	madvise(vm->mem, mem_size, MADV_MERGEABLE);

	memreg.slot = 0;
	memreg.flags = 0;
	memreg.guest_phys_addr = 0;
	memreg.memory_size = mem_size;
	memreg.userspace_addr = (unsigned long)vm->mem;
        if (ioctl(vm->fd, KVM_SET_USER_MEMORY_REGION, &memreg) < 0) {
		perror("KVM_SET_USER_MEMORY_REGION");
                exit(1);
	}
}

struct vcpu {
	int fd;
	struct kvm_run *kvm_run;
};

void child_vcpu_init(struct vcpu *parent_vcpu, struct vm *vm, struct vcpu *vcpu)
{
	int vcpu_mmap_size;

	vcpu->fd = ioctl(vm->fd, KVM_CREATE_VCPU, 0);
        if (vcpu->fd < 0) {
		perror("KVM_CREATE_VCPU");
                exit(1);
	}

	vcpu_mmap_size = ioctl(vm->sys_fd, KVM_GET_VCPU_MMAP_SIZE, 0);
        if (vcpu_mmap_size <= 0) {
		perror("KVM_GET_VCPU_MMAP_SIZE");
                exit(1);
	}

	vcpu->kvm_run = parent_vcpu->kvm_run;
	if (vcpu->kvm_run == MAP_FAILED) {
		perror("mmap kvm_run");
		exit(1);
	}
}


void vcpu_init(struct vm *vm, struct vcpu *vcpu)
{
	int vcpu_mmap_size;
	int res = 1;
	// struct kvm_enable_cap {
	// 	/* in */
	// 	__u32 cap;


	// 	__u32 flags;


	// 	__u64 args[4];


	// 	__u8  pad[64];
	// } fork_cap;

	struct kvm_enable_cap fork_cap = {
        .cap = 180,
        .flags = 0,
    };

	printf(" %u \n", fork_cap.cap);
	vcpu->fd = ioctl(vm->fd, KVM_CREATE_VCPU, 0);
        if (vcpu->fd < 0) {
		perror("KVM_CREATE_VCPU");
                exit(1);
	}
	// res = ioctl(vm->fd, 0xaec5);
	printf(" ----------> res %u\n\n", res );

	vcpu_mmap_size = ioctl(vm->sys_fd, KVM_GET_VCPU_MMAP_SIZE, 0);
        if (vcpu_mmap_size <= 0) {
		perror("KVM_GET_VCPU_MMAP_SIZE");
                exit(1);
	}

	vcpu->kvm_run = mmap(NULL, vcpu_mmap_size, PROT_READ | PROT_WRITE,
			     MAP_SHARED, vcpu->fd, 0);
	if (vcpu->kvm_run == MAP_FAILED) {
		perror("mmap kvm_run");
		exit(1);
	}
}
int child_run_vm(struct vm *vm, struct vcpu *vcpu, size_t sz)
{
	struct kvm_regs regs;
	uint64_t memval = 0;
	int r = 0;
	printf("vm----\n");
	for (int i=0;; i++) {
		r = ioctl(vcpu->fd, KVM_RUN, 0);
		printf("\n value of r === %d\n", r);
		if (r < 0) {
			perror("KVM_RUN - ioctl: ");
			exit(1);
		}

		switch (vcpu->kvm_run->exit_reason) {
		case KVM_EXIT_HLT:
			goto check;

		case KVM_EXIT_IO:
			if (vcpu->kvm_run->io.direction == KVM_EXIT_IO_OUT
				&& vcpu->kvm_run->io.port == 0xE9) {
				char *p = (char *)vcpu->kvm_run;
				fwrite(p + vcpu->kvm_run->io.data_offset,
						vcpu->kvm_run->io.size, 1, stdout);
				fflush(stdout);
				continue;
			}

			/* fall through */
		default:
			
			fprintf(stderr,	"Got exit_reason %d,"
				" expected KVM_EXIT_HLT (%d)\n",
				vcpu->kvm_run->exit_reason, KVM_EXIT_HLT);
			exit(1);
		}
	}

 check:
	if (ioctl(vcpu->fd, KVM_GET_REGS, &regs) < 0) {
		perror("KVM_GET_REGS");
		exit(1);
	}

	memcpy(&memval, &vm->mem[0x400], sz);
	// if (regs.rax != 42) {
	// 	printf("Wrong result: {E,R,}AX is %lld\n", regs.rax);
	// 	printf("Wrong result: memory at 0x400 is %lld\n",
	// 	       (unsigned long long)memval);
	// 	if(regs.rax == 43){
	// 		return 0;
	// 	}
	// 	// goto restart;

	// 	return 1;
	// }

	// if (memval != 42) {
	// 	printf("Wrong result: memory at 0x400 is %lld\n",
	// 	       (unsigned long long)memval);
	// 	if(memval == 20){
	// 		return 0;
	// 	}
	// 	// goto restart;
	// 	return 1;
	// }
	return 0;
}

extern const unsigned char guest16[], guest16_end[];
extern const unsigned char guest64[], guest64_end[];

void fork_child(struct vm *parent_vm, struct kvm_sregs parent_sregs, struct kvm_regs parent_regs){
	struct vm vm; 
	struct vcpu vcpu; 
	// struct kvm_sregs parent_sregs;
	// struct kvm_regs parent_regs;

	child_vm_init(parent_vm, &vm, 0x200000);
	vcpu_init(&vm, &vcpu);
	
	if (ioctl(vcpu.fd, KVM_SET_SREGS, &parent_sregs) < 0) {
		perror("KVM_SET_SREGS");
		exit(1);
	}
	if (ioctl(vcpu.fd, KVM_SET_REGS, &parent_regs) < 0) {
		perror("KVM_SET_REGS");
		exit(1);
	}
	// memcpy(vm.mem, guest64, guest64_end-guest64); //Todo : remove it 
	child_run_vm(&vm, &vcpu, 8);
	return; 
}

struct fork_info { 
	struct kvm_userspace_memory_region memreg;
	int vm_fd;
	int vcpu_fd;
};

void fork_child_with_ioctl(struct fork_info *info, int sys_fd,struct kvm_regs parent_regs, struct kvm_sregs parent_sregs){
	struct vm vm;
	struct vcpu vcpu;
	int vcpu_mmap_size;
	
	vm.sys_fd = sys_fd;
	printf("%u", sys_fd);
	
	//putting values in vcpu struct 
	vcpu.fd = info->vcpu_fd;

	//putting values in vm struct 
	vm.fd = info->vm_fd;
	vm.mem = (char *)info->memreg.userspace_addr;

	//setting up the kvm run for the vcpu
	vcpu_mmap_size = ioctl(vm.sys_fd, KVM_GET_VCPU_MMAP_SIZE, 0);
        if (vcpu_mmap_size <= 0) {
		perror("KVM_GET_VCPU_MMAP_SIZE");
                exit(1);
	}
	printf("fork");

	vcpu.kvm_run = mmap(NULL, vcpu_mmap_size, PROT_READ | PROT_WRITE,
			     MAP_SHARED, vcpu.fd, 0);
	if (vcpu.kvm_run == MAP_FAILED) {
		perror("mmap kvm_run");
		exit(1);
	}			

	if (ioctl(vcpu.fd, KVM_SET_SREGS, &parent_sregs) < 0) {
		perror("KVM_SET_SREGS");
		exit(1);
	}
	if (ioctl(vcpu.fd, KVM_SET_REGS, &parent_regs) < 0) {
		perror("KVM_SET_REGS");
		exit(1);
	}	
	

	child_run_vm(&vm, &vcpu, 8);
	return;
}

int run_vm(struct vm *vm, struct vcpu *vcpu, size_t sz)
{
	struct kvm_sregs parent_sregs;
	struct kvm_regs parent_regs;
	struct fork_info info;

	uint64_t memval = 0;

restart:
	for (int i = 0;; i++) {
		if (ioctl(vcpu->fd, KVM_RUN, 0) < 0) {
			perror("KVM_RUN - fc");
			exit(1);
		}
		
		

		
		switch (vcpu->kvm_run->exit_reason) {
		case KVM_EXIT_HLT:
			if (ioctl(vcpu->fd, KVM_GET_SREGS, &parent_sregs) < 0) {
				perror("KVM_GET_SREGS - fc");
				exit(1);
			}
			if (ioctl(vcpu->fd, KVM_GET_REGS, &parent_regs) < 0) {
				perror("KVM_GET_SREGS - fc");
				exit(1);
			}
			printf("---------->>>> parent CR3 : %llu", parent_sregs.cr3);
			if (parent_regs.rax == 42)
			{				
				if(MODE == 1){
					if(syscall(439) == 0){
						printf("== Child VM Started====\n");
						//do work for the child 
						//setup the vm --> with the same memory as that of the parent store in the 
						//in vm->mem =====> Do all of the child vm init
						//setup a vcpu --> set its sreg and reg the same as that of the parent vcpu  
						fork_child(vm, parent_sregs, parent_regs);
						printf("== Child VM Ended====\n");
						return 0;
					} else {
						wait(NULL);
					}
				} else if (MODE == 0) {
					if(fork() == 0){
						printf("== Child VM Started====\n");
						//do work for the child 
						//setup the vm --> with the same memory as that of the parent store in the 
						//in vm->mem =====> Do all of the child vm init
						//setup a vcpu --> set its sreg and reg the same as that of the parent vcpu   
						info.memreg.slot = 0;
						info.memreg.flags = 0;
						info.memreg.guest_phys_addr = 0;
						info.memreg.memory_size = 0x200000;
						info.memreg.userspace_addr = (unsigned long)vm->mem;
						printf("Userspace value of vm-> mem %lu", (unsigned long)vm->mem);
						// fork_child(vm, parent_sregs, parent_regs);
						printf("vm fd ::::: > %lu\n", (unsigned long)vm->fd);
						printf("vm fd ::::: > %lu\n", (unsigned long)vm->sys_fd);
						ioctl(vm->sys_fd, 0xc028aec5, &info);
						printf(" The fd of the vcpu : %u\n", info.vcpu_fd);
						printf(" The fd of the vm : %u\n", info.vm_fd);
						printf(" The mem the vm : %lu\n", (unsigned long)info.memreg.userspace_addr);
						fork_child_with_ioctl(&info, vm->sys_fd, parent_regs, parent_sregs);
					
						
						printf("== Child VM Ended====\n");
						return 0;
					} else {
						wait(NULL);
					}	
				}
				else
					goto restart;
			}
			else
				goto check_p;

		case KVM_EXIT_IO:
			if (vcpu->kvm_run->io.direction == KVM_EXIT_IO_OUT
			    && vcpu->kvm_run->io.port == 0xE9) {
				char *p = (char *)vcpu->kvm_run;
				fwrite(p + vcpu->kvm_run->io.data_offset,
				       vcpu->kvm_run->io.size, 1, stdout);
				fflush(stdout);
				continue;
			}

			/* fall through */
		default:
			fprintf(stderr,	"Got exit_reason %d,"
				" expected KVM_EXIT_HLT (%d)\n",
				vcpu->kvm_run->exit_reason, KVM_EXIT_HLT);
			exit(1);
		}
	}

check_p:
	if (ioctl(vcpu->fd, KVM_GET_REGS, &parent_regs) < 0) {
		perror("KVM_GET_REGS");
		exit(1);
	}
	// if (regs.rax != 42) {
	// 	printf("Wrong result: {E,R,}AX is %lld\n", regs.rax);
	// 	return 0;
	// }

	memcpy(&memval, &vm->mem[0x400], sz);

	// if (memval != 42) {
	// 	printf("Wrong result: memory at 0x400 is %lld\n",
	// 	       (unsigned long long)memval);
	// 	return 0;
	// }

	return 0;
}




int run_real_mode(struct vm *vm, struct vcpu *vcpu)
{
	struct kvm_sregs sregs;
	struct kvm_regs regs;

	printf("Testing real mode\n");

        if (ioctl(vcpu->fd, KVM_GET_SREGS, &sregs) < 0) {
		perror("KVM_GET_SREGS");
		exit(1);
	}

	sregs.cs.selector = 0;
	sregs.cs.base = 0;

        if (ioctl(vcpu->fd, KVM_SET_SREGS, &sregs) < 0) {
		perror("KVM_SET_SREGS");
		exit(1);
	}

	memset(&regs, 0, sizeof(regs));
	/* Clear all FLAGS bits, except bit 1 which is always set. */
	regs.rflags = 2;
	regs.rip = 0;

	if (ioctl(vcpu->fd, KVM_SET_REGS, &regs) < 0) {
		perror("KVM_SET_REGS");
		exit(1);
	}

	memcpy(vm->mem, guest16, guest16_end-guest16);
	return run_vm(vm, vcpu, 2);
}

static void setup_protected_mode(struct kvm_sregs *sregs)
{
	struct kvm_segment seg = {
		.base = 0,
		.limit = 0xffffffff,
		.selector = 1 << 3,
		.present = 1,
		.type = 11, /* Code: execute, read, accessed */
		.dpl = 0,
		.db = 1,
		.s = 1, /* Code/data */
		.l = 0,
		.g = 1, /* 4KB granularity */
	};

	sregs->cr0 |= CR0_PE; /* enter protected mode */

	sregs->cs = seg;

	seg.type = 3; /* Data: read/write, accessed */
	seg.selector = 2 << 3;
	sregs->ds = sregs->es = sregs->fs = sregs->gs = sregs->ss = seg;
}

extern const unsigned char guest32[], guest32_end[];

int run_protected_mode(struct vm *vm, struct vcpu *vcpu)
{
	struct kvm_sregs sregs;
	struct kvm_regs regs;

	printf("Testing protected mode\n");

        if (ioctl(vcpu->fd, KVM_GET_SREGS, &sregs) < 0) {
		perror("KVM_GET_SREGS");
		exit(1);
	}

	setup_protected_mode(&sregs);

        if (ioctl(vcpu->fd, KVM_SET_SREGS, &sregs) < 0) {
		perror("KVM_SET_SREGS");
		exit(1);
	}

	memset(&regs, 0, sizeof(regs));
	/* Clear all FLAGS bits, except bit 1 which is always set. */
	regs.rflags = 2;
	regs.rip = 0;

	if (ioctl(vcpu->fd, KVM_SET_REGS, &regs) < 0) {
		perror("KVM_SET_REGS");
		exit(1);
	}

	memcpy(vm->mem, guest32, guest32_end-guest32);
	return run_vm(vm, vcpu, 4);
}

static void setup_paged_32bit_mode(struct vm *vm, struct kvm_sregs *sregs)
{
	uint32_t pd_addr = 0x2000;
	uint32_t *pd = (void *)(vm->mem + pd_addr);

	/* A single 4MB page to cover the memory region */
	pd[0] = PDE32_PRESENT | PDE32_RW | PDE32_USER | PDE32_PS;
	/* Other PDEs are left zeroed, meaning not present. */

	sregs->cr3 = pd_addr;
	sregs->cr4 = CR4_PSE;
	sregs->cr0
		= CR0_PE | CR0_MP | CR0_ET | CR0_NE | CR0_WP | CR0_AM | CR0_PG;
	sregs->efer = 0;
}

int run_paged_32bit_mode(struct vm *vm, struct vcpu *vcpu)
{
	struct kvm_sregs sregs;
	struct kvm_regs regs;

	printf("Testing 32-bit paging\n");

        if (ioctl(vcpu->fd, KVM_GET_SREGS, &sregs) < 0) {
		perror("KVM_GET_SREGS");
		exit(1);
	}

	setup_protected_mode(&sregs);
	setup_paged_32bit_mode(vm, &sregs);

        if (ioctl(vcpu->fd, KVM_SET_SREGS, &sregs) < 0) {
		perror("KVM_SET_SREGS");
		exit(1);
	}

	memset(&regs, 0, sizeof(regs));
	/* Clear all FLAGS bits, except bit 1 which is always set. */
	regs.rflags = 2;
	regs.rip = 0;

	if (ioctl(vcpu->fd, KVM_SET_REGS, &regs) < 0) {
		perror("KVM_SET_REGS");
		exit(1);
	}

	memcpy(vm->mem, guest32, guest32_end-guest32);
	return run_vm(vm, vcpu, 4);
}

static void setup_64bit_code_segment(struct kvm_sregs *sregs)
{
	struct kvm_segment seg = {
		.base = 0,
		.limit = 0xffffffff,
		.selector = 1 << 3,
		.present = 1,
		.type = 11, /* Code: execute, read, accessed */
		.dpl = 0,
		.db = 0,
		.s = 1, /* Code/data */
		.l = 1,
		.g = 1, /* 4KB granularity */
	};

	sregs->cs = seg;

	seg.type = 3; /* Data: read/write, accessed */
	seg.selector = 2 << 3;
	sregs->ds = sregs->es = sregs->fs = sregs->gs = sregs->ss = seg;
}

static void setup_long_mode(struct vm *vm, struct kvm_sregs *sregs)
{
	uint64_t pml4_addr = 0x20000;
	uint64_t *pml4 = (void *)(vm->mem + pml4_addr);

	uint64_t pdpt_addr = 0x3000;
	uint64_t *pdpt = (void *)(vm->mem + pdpt_addr);

	uint64_t pd_addr = 0x4000;
	uint64_t *pd = (void *)(vm->mem + pd_addr);

	pml4[0] = PDE64_PRESENT | PDE64_RW | PDE64_USER | pdpt_addr;
	pdpt[0] = PDE64_PRESENT | PDE64_RW | PDE64_USER | pd_addr;
	pd[0] = PDE64_PRESENT | PDE64_RW | PDE64_USER | PDE64_PS;

	sregs->cr3 = pml4_addr;
	sregs->cr4 = CR4_PAE;
	sregs->cr0
		= CR0_PE | CR0_MP | CR0_ET | CR0_NE | CR0_WP | CR0_AM | CR0_PG;
	sregs->efer = EFER_LME | EFER_LMA;

	setup_64bit_code_segment(sregs);
	
}


int run_long_mode(struct vm *vm, struct vcpu *vcpu)
{
	struct kvm_sregs sregs;
	struct kvm_regs regs;
	
	printf("Testing 64-bit mode\n");

     
	if (ioctl(vcpu->fd, KVM_GET_SREGS, &sregs) < 0) {
		perror("KVM_GET_SREGS - rlm");
		exit(1);
	}
	setup_long_mode(vm, &sregs);

    if (ioctl(vcpu->fd, KVM_SET_SREGS, &sregs) < 0) {
		perror("KVM_SET_SREGS");
		exit(1);
	}


	// if in the child vcpu don't set up the regs or the sregs 
	// use the ones that have been left behind by the original one 
	
	memset(&regs, 0, sizeof(regs));
	/* Clear all FLAGS bits, except bit 1 which is always set. */
	regs.rflags = 2;
	regs.rip = 0;
	/* Create stack at top of 2 MB page and grow down. */
	regs.rsp = 2 << 20;

	if (ioctl(vcpu->fd, KVM_SET_REGS, &regs) < 0) {
		perror("KVM_SET_REGS");
		exit(1);
	}
	memcpy(vm->mem, guest64, guest64_end-guest64);
	// if(fork() == 0){
	// 	//do work for the child 
	// 	//setup the vm --> with the same memory as that of the parent store in the 
	// 	//in vm->mem =====> Do all of the child vm init
	// 	//setup a vcpu --> set its sreg and reg the same as that of the parent vcpu  
	// 	fork_child(vm, vcpu);
	// } else { 
	run_vm(vm, vcpu, 8);
	return 0;
}

int main(int argc, char **argv)
{
	struct vm vm;
	struct vm parent_vm;
	struct vcpu vcpu;
	struct vcpu parent_vcpu;
	// clock_t start_clk;

	enum {
		REAL_MODE,
		PROTECTED_MODE,
		PAGED_32BIT_MODE,
		LONG_MODE,
	} mode = REAL_MODE;
	int opt;

	while ((opt = getopt(argc, argv, "rspl102")) != -1) {
		switch (opt) {
		case 'r':
			mode = REAL_MODE;
			break;

		case 's':
			mode = PROTECTED_MODE;
			break;

		case 'p':
			mode = PAGED_32BIT_MODE;
			break;

		case 'l':
			mode = LONG_MODE;
			break;

		case '1':
			MODE = 1;
			break;

		case '0':
			MODE = 0;
			break;
		
		case '2':
			MODE = 2;
			break; 

		default:
			fprintf(stderr, "Usage: %s [ -r | -s | -p | -l ] [-1 | -0 | -2]\n",
				argv[0]);
			return 1;
		}
	}


	// start_clk = clock();
	vm_init(&parent_vm, 0x200000);
	// printf("\nTime for vm init (parent) %lg \n", (clock() - start_clk) / (double) CLOCKS_PER_SEC);
	// start_clk = clock();
	vcpu_init(&parent_vm, &parent_vcpu);
	// printf("\nTime for vcpu init (parent) %lg \n", (clock() - start_clk) / (double) CLOCKS_PER_SEC);
	
	// child_vcpu_init(&parent_vcpu, &vm, &vcpu);

	switch (mode) {
	case REAL_MODE:
		return !run_real_mode(&vm, &vcpu);

	case PROTECTED_MODE:
		return !run_protected_mode(&vm, &vcpu);

	case PAGED_32BIT_MODE:
		return !run_paged_32bit_mode(&vm, &vcpu);

	case LONG_MODE:
		// start_clk = clock();
		// child_vm_init(&parent_vm, &vm, 0x200000);
		// printf("\nTime for VM init(child): %lg\n", (clock() - start_clk) / (double) CLOCKS_PER_SEC);
		// start_clk = clock();
		// vcpu_init(&vm, &vcpu);
		// printf("\nTime for VCPU init(child): %lg\n", (clock() - start_clk) / (double) CLOCKS_PER_SEC);
		// start_clk = clock();
		// MODE = 1;
		run_long_mode(&parent_vm, &parent_vcpu);
		// run_long_mode(NULL, &parent_vm, &parent_vcpu);
		// run_long_mode(&parent_vcpu, &vm, &vcpu);
		// printf("\nDid calls in %lg seconds\n", (clock() - start_clk) / (double) CLOCKS_PER_SEC);
 		
		return 0;
	}

	return 1;
}
