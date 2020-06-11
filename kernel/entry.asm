[bits 32]

; Kernel code is loaded into address 0x1000. This is the start of that code.
; It will then proceed to jump to the main function (the linker will set main 
; to be the correct address)

[extern main] ; linker will subsitute the symbol main with the correct address

call main
jmp $ ; after returning from kernel