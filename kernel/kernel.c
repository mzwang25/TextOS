#include "../drivers/screen.h"
#include "../mlib/print.h"
#include "../mlib/stack32.h"
#include "../cpu/isr.h"
#include "../drivers/keyboard.h"
#include "../mlib/paging.h"
#include "../mlib/kmalloc.h"
#include "../mlib/types.h"

void main()
{
    clear_screen();
    strprint("Hello! You entered the Kernel!\n");

    asm volatile("sti");
    isr_install();

    initialize_paging();

    uint32_t *ptr = (uint32_t*) 0xA0000000;
    uint32_t do_page_fault = *ptr;
}