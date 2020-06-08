; Load number of sectors (in dh) to es:bx from drive dl

disk_load:
    push dx ; this contains registers %dh and %dl

    mov ah, 0x02 ; BIOS read sector
    mov al, dh ; Read sectors from DH
    mov ch, 0x00 ; cylinder 0
    mov dh, 0x00 ; head 0
    mov cl, 0x02 ; second sector

    int 0x13 ; BIOS interrupt

    ;al is set to the number of sectors actually read
    jc disc_error ; Jump if carry flag set (which means error) 

    pop dx ; dx (containing dh) was pushed into stack at beginning (contains num of sectors to read)
    cmp dh, al ; al contained number of original sectors
    jne dist_error
    ret 

disk_error:
    mov bx, DISK_ERROR_MSG
    call print_string
    jmp $

DISK_ERROR_MSG: db "Disk Read Error", 0
