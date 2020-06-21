#include "paging.h"
#include "print.h"
#include "kmalloc.h"
#include "../cpu/isr.h"

uint32_t page_directory[PAGE_DIR_ENTRIES] __attribute__((aligned(4096)));
uint32_t* first_page_table;

void handle_page_fault(registers_t r)
{
    printstr("***Page Fault!***\n");

    while(1); //spin for now
}

void initialize_paging()
{
    int i;
    for(i = 0; i < 1024; i++)
    {
        page_directory[i] = 0x00000002;
    }

    uint32_t* first_page_table = kmalloc(1024 * 4);
    for(i = 0; i < 1024; i++)
    {
        first_page_table[i] = (i * 0x1000) | 3; // attributes: supervisor level, read/write, present.
    }

    page_directory[0] = ((uint32_t) first_page_table) | 3;

    set_int_handler(14, handle_page_fault);

    //assembly move into cr3
    asm volatile("mov %0, %%cr3" :: "r" (&page_directory));
    //set cr0
    uint32_t cr0;
    asm volatile("mov %%cr0, %0" : "=r" (cr0));
    cr0 |= 0x80000000;
    asm volatile("mov %0, %%cr0" :: "r"(cr0));
}
