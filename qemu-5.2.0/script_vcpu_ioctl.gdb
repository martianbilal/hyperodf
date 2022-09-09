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
        printf "[gdb] called kvm_vcpu_ioctl\n"
        bt
        c
    end
    c
end



r