b accel/kvm/kvm-all.c:3415
commands 
    printf "[gdb] KVM State when we received the call for fork!\n"
    p *s
    c
end

b softmmu/vl.c:3533
commands
    printf "[gdb] KVM State when after hyperODF post fork setup\n"
    p *cpu
    c
end


b softmmu/vl.c:3541
commands
    printf "[gdb] KVM State when we are returned from load_snapshot_memory!\n"
    p *cpu
    c
end

r