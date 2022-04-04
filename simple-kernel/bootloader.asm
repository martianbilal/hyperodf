
[org 0x7c00]

mov [BOOT_DISK], dl

mov bp, 0x7c00 ;stack base pointer
mov sp, bp     ;stack pointer

; s:
;     mov [0xfedc], dword 0xdeadbeef
;     ; jmp l
; ; l:
;     mov eax, dword [0xfedc]
;     add eax, 1
;     mov [0xfedd], eax




; mov bx, helloWorld
; call printString


; mov eax, 65h
; mov dx, 300h
; out dx, eax

; mov eax, 65h
; mov dx, 300h
; out dx, eax



; this is the hypercall for FORK
mov eax, 63h
mov dx, 301h
out dx, eax

mov bx, helloWorld
call printString

call readDisk

; mov ax, 65h
; mov dx, 300h
; out dx, ax


; printing the first "h" we have written on disk
; mov ah, 0x0e
; mov al, [PROGRAM_SPACE]
; int 0x10

; mov bx, helloWorld
; call printString

; mov ax, [PROGRAM_SPACE]
; mov dx, 300h
; out dx, ax

mov ax, 63h
mov dx, 300h
out dx, ax


jmp $





%include "print.asm"
%include "diskRead.asm"


times 510-($-$$) db 0

dw 0xaa55
