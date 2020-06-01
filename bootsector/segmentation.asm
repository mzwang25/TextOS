
; set ds to start of segment
mov bx, 0x7c0 ; can't set ds directly though :(
mov ds, bx ; seems like we can only copy from another register
mov al, [the_secret]
int 0x10

; can also do it with es
mov es, bx
mov al, [es:the_secret]
int 0x10

the_secret:
    db "X"