PROGRAM_SPACE equ 0x7e00

writeDisk:
    mov ah, 0x03
    mov al, 2 ;4 sectors, about 4000b bytes
    mov dl, [BOOT_DISK]
    mov ch, 0x00 ;0 cylinder 
    mov dh, 0x00 ;0 head
    mov cl, 0x02 ;describing the sector that we will be reading
    ; xor ax, ax
    ; mov es, ax    ; ES <- 0
    ; mov cx, 1     ; cylinder 0, sector 1
    ; mov dx, 0080h ; DH = 0 (head), drive = 80h (0th hard disk)
    mov bx, DiskWrite ; segment offset of the buffer
    ; mov ax, 0301h ; AH = 03 (disk write), AL = 01 (number of sectors to write)
    int 13h
    jc DiskWriteFailed
    ret

DiskWrite:
    db 'CHANGE',0

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

; reading timer values 
readTimer:
    pusha
    mov ah, 0x00
    int 0x1a
    popa
    ret

BOOT_DISK: 
    db 0

DiskReadErrorString:
    db 'Disk read failed',0

DiskWriteErrorString:
    db 'Disk write failed',0

DiskSuccessString:
    db 'Disk read passed',0

DiskWriteFailed:
    mov bx, DiskWriteErrorString
    call printString
    jmp $


DiskReadFailed:
    mov bx, DiskReadErrorString
    call printString
    jmp $


