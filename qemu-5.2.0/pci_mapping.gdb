b vapic_reset
commands
    printf "[gdb] vapic_reset\n"
    bt 
    printf "[gdb] vapic_reset arg \n"
    p *dev
    c
end

b vapic_realize
commands
    printf "[gdb] vapic_realize\n"
    bt 
    printf "[gdb] vapic_realize arg \n"
    p *dev
    c
end

b vapic_prepare
commands
    printf "[gdb] vapic_prepare\n"
    bt 
    printf "[gdb] vapic_prepare arg \n"
    p *s
    c
end

b read_guest_rom_state
commands
    printf "[gdb] read_guest_rom_state\n"
    bt 
    printf "[gdb] read_guest_rom_state arg \n"
    p *s
    c
end

b evaluate_tpr_instruction
commands
    printf "[gdb] evaluate_tpr_instruction\n"
    bt 
    printf "[gdb] evaluate_tpr_instruction arg \n"
    p *s
    c
end

b find_real_tpr_addr
commands
    printf "[gdb] find_real_tpr_addr\n"
    bt 
    printf "[gdb] find_real_tpr_addr arg \n"
    p *s
    c
end

b read_guest_rom_state
commands
    printf "[gdb] read_guest_rom_state\n"
    bt 
    printf "[gdb] read_guest_rom_state arg \n"
    p *s
    c
end


b vapic_map_rom_writable
commands
    printf "[gdb] vapic_map_rom_writable\n"
    bt 
    printf "[gdb] vapic_map_rom_writable arg \n"
    p *s
    c
end


b write_guest_rom_state
commands
    printf "[gdb] write_guest_rom_state\n"
    bt 
    printf "[gdb] write_guest_rom_state arg \n"
    p *s
    c
end


r
