; Global Offset 0x7c00 (where boot sector starts)
[org 0x7c00]
KERNEL_OFFSET equ 0x1000 ; Location to load kernel into

; The bootsector is 512 bytes and must end with word 0xaa55
; Operates in 16-bit mode

; Set the stack
mov bp, 0x8000
mov sp, bp

; Print Bootsector Msg
mov bx, intro
call print_string

; Load kernel into memory
call load_kernel

; Switch into 32-bit protected mode
call switch_to_pm

; Hang
jmp $

%include "boot/print.asm"
%include "boot/read_disk.asm"
%include "boot/32bit-print.asm"
%include "boot/32bit-switch.asm"
%include "boot/32bit-gdt.asm"
%include "boot/load_kernel.asm"

[bits 32]
BEGIN_PM: ; after switching into 32-bit mode, it'll jump here
    ; This is 32-bit mode
    call KERNEL_OFFSET ; enter into kernel code
    jmp $

BOOT_DRIVE:
    db 0

intro:
    db 'Bootsector Loaded!', 0xa, 0xd, 0 ; 0xa newline and 0xd cr


; This tells the assembler to pad with 0s until 510's byte 
; $ is current position and $$ is beginning of section .. so ($-$$) is
; how far into current section. So padding with byte 0 510-($-$$) times
times 510-($-$$) db 0

; This fills the last two bytes with the magic word
dw 0xaa55

