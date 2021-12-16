mov ah, 0x0e ; tty mode

s:
    mov [0xfedc], dword 0xdeadbeef
    ; jmp l
; l:
    mov eax, dword [0xfedc]
    add eax, 1
    mov [0xfedd], eax
    jmp infinite
; mov [0xf10], byte 0xbb
; mov [0xf20], byte 0xcc
; mov [0xf30], byte 0xdd
; mov eax, dword [0xf00]
; mov bl, [0xf10]
; mov cl, [0xf20]
; mov dl, [0xf30]

infinite:
    mov eax, 63h
    mov dx, 300h 
    out dx, eax
    jmp infinite ; jump to current address = infinite loop

;times 510-($-$$) db 0
;dw 0xAA55
; padding and magic number
times 510 - ($-$$) db 0
dw 0xaa55 
