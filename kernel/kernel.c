#include "../drivers/screen.h"
#include "../mlib/print.h"
#include "../mlib/stack32.h"
#include "../cpu/isr.h"
#include "../drivers/keyboard.h"
#include "../mlib/paging.h"
#include "../mlib/kmalloc.h"

void main()
{
    clear_screen();
    strprint("Hello! You entered the Kernel!\n");

    //asm volatile("sti");
    //isr_install();
    //initialize_keyboard();

    initialize_paging();

}