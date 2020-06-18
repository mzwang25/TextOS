#include "../drivers/screen.h"
#include "../mlib/print.h"
#include "../mlib/stack32.h"
#include "../cpu/isr.h"
#include "../drivers/keyboard.h"
#include "../mlib/mem.h"

void main()
{
    //asm volatile("sti");
    //isr_install();
    //initialize_keyboard();
    clear_screen();

    strprint("Hello! You entered the Kernel!\n");

    uint32_t ret1 = kmalloc_a(20);
    uint32_t ret2 = kmalloc_a(20);

}