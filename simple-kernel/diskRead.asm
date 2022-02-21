PROGRAM_SPACE equ 0x7e00

readDisk:
    mov ah, 0x02
    mov bx, PROGRAM_SPACE
    mov al, 2 ;4 sectors, about 4000b bytes
    mov dl, [BOOT_DISK]
    mov ch, 0x00 ;0 cylinder 
    mov dh, 0x00 ;0 head
    mov cl, 0x02 ;describing the sector that we will be reading
    int 0x13
    jc DiskReadFailed
    ret

BOOT_DISK: 
    db 0

DiskReadErrorString:
    db 'Disk read failed',0

DiskReadFailed:
    mov bx, DiskReadErrorString
    call printString
    jmp $
