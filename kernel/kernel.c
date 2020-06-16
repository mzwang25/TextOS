#include "../drivers/screen.h"
#include "../mlib/print.h"
#include "../mlib/stack32.h"
#include "../cpu/isr.h"

void main()
{
    clear_screen();
    strprint("Hello! You entered the Kernel\n");

    isr_install();
    __asm__ __volatile__("int $2");
}