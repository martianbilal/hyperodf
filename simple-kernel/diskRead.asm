PROGRAM_SPACE equ 0x7e00

readDisk:
    ; pusha
    ; push dx
    mov ah, 0x02
    mov bx, PROGRAM_SPACE
    mov al, 2 ;4 sectors, about 4000b bytes
    mov dl, [BOOT_DISK]
    mov ch, 0x00 ;0 cylinder 
    mov dh, 0x00 ;0 head
    mov cl, 0x02 ;describing the sector that we will be reading
    int 0x13
    jc DiskReadFailed
    ; pop dx
    ; cmp al, dh
    ; jne DiskReadFailed
    ; popa
    ret

BOOT_DISK: 
    db 0

DiskReadErrorString:
    db 'Disk read failed',0

DiskSuccessString:
    db 'Disk read passed',0

DiskReadFailed:
    mov bx, DiskReadErrorString
    call printString
    jmp $
