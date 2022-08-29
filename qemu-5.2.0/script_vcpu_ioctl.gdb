b load_snapshot_memory
commands 
    printf "[gdb] starting the load snapshot\n"
    b kvm_vcpu_ioctl
    commands
        printf "[gdb] called kvm_vcpu_ioctl\n"
        bt
        c
    end
    c
end

b softmmu/vl.c:3541
commands
    printf "[gdb] ended load_snapshot_memor\n"
    d 1 
    d 2
    d 3
    c
end


r