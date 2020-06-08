; Global Offset 0x7c00 (where boot sector starts)
[org 0x7c00]

; The bootsector is 512 bytes and must end with word 0xaa55
; Operates in 16-bit mode

mov bx, intro
call print_string
jmp $

%include "print.asm"

intro:
    db 'Bootsector Loaded!', 0

; This tells the assembler to pad with 0s until 510's byte 
; $ is current position and $$ is beginning of section .. so ($-$$) is
; how far into current section. So padding with byte 0 510-($-$$) times
times 510-($-$$) db 0

; This fills the last two bytes with the magic word
dw 0xaa55
