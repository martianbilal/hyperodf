set $cpu_breaks = 0

b accel/kvm/kvm-all.c:3524
b accel/kvm/kvm-all.c:3539

commands 1
    b accel/kvm/kvm-all.c:3124
    printf " ============ Starting logs for the kvm mem set ============\n"
    commands 4
        p mem
        c
    end
    c
end

commands 2
    printf " ============ Ending logs for the kvm mem set ============\n"
    d 4
    c
end

b load_snapshot_memory

commands 3    
    printf " ============ Start Log ============\n"
    bt
    printf " ============ End Log ============\n"
    b kvm_vm_ioctl 
    b accel/kvm/kvm-all.c:522
    commands 6
        p mem
        c
    end
    commands 5
        bt
        if $cpu_breaks == 0
            b kvm_cpu_exec
            set $cpu_breaks = 1
        end
        commands 7
            d 5
            d 6
            d 7
            c
        end
        c
    end
    c
end
r