set $cpu_breaks = 0

b load_snapshot_memory

commands 1    
    printf " ============ Start Log ============\n"
    bt
    printf " ============ End Log ============\n"
    b kvm_vm_ioctl 
    b accel/kvm/kvm-all.c:522
    commands 3
        p mem
        c
    end
    commands 2
        bt
        if $cpu_breaks == 0
            b kvm_cpu_exec
            set $cpu_breaks = 1
        end
        commands 4
            d 2
            d 3
            d 4
            c
        end
        c
    end
    c
end
r