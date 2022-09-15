
b accel/kvm/kvm-all.c:3532
commands
    printf "[gdb] cpu after post_fork \n"
    p *cpu
    c
end

b accel/kvm/kvm-all.c:3533
commands
    printf "[gdb] cpu after init\n"
    p *cpu
    c
end


r
