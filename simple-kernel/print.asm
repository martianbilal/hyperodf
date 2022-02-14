printString:
    mov ah, 0x0e 
    .loop: 
        cmp [bx], byte 0
        je .Exit
        mov al, [bx]
        int 0x10 ; interrupt to print lower part of a 'al'
        inc bx
        jmp .loop
    .Exit:
        ret 

    
helloWorld: 
    db 'Hello World',0