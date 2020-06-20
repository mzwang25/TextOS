#include "paging.h"
#include "print.h"
#include "kmalloc.h"
#include "../cpu/isr.h"

void handle_page_fault(registers_t r)
{
    printstr("page fault\n");
}

/**
 * CR3 -> page_dir and each page_dir entry contains a page_table
 * More info in notes/paging.png
 */

uint32_t page_directory[PAGE_DIR_ENTRIES] __attribute__((aligned(4096)));
uint32_t first_page_table[1024] __attribute__((aligned(4096)));

void initialize_paging()
{
    int i;
    for(i = 0; i < 1024; i++)
    {
        page_directory[i] = 0x00000002;
    }

    //we will fill all 1024 entries in the table, mapping 4 megabytes
    for(i = 0; i < 1024; i++)
    {
        // As the address is page aligned, it will always leave 12 bits zeroed.
        // Those bits are used by the attributes ;)
        first_page_table[i] = (i * 0x1000) | 3; // attributes: supervisor level, read/write, present.
    }

    page_directory[0] = ((uint32_t) first_page_table) | 3;

    //assembly move into cr3
    asm volatile("mov %0, %%cr3" :: "r" (&page_directory));
    //set cr0
    uint32_t cr0;
    asm volatile("mov %%cr0, %0" : "=r" (cr0));
    cr0 |= 0x80000000;
    asm volatile("mov %0, %%cr0" :: "r"(cr0));

    printstr("here");
    while(1)
        ;
}

/*
void initialize_paging()
{
    //create page dir
    int i = 0;
    int j = 0;
    uint32_t addr = 0;

    for(i = 0; i < PAGE_DIR_ENTRIES; i++)
    {
        if(addr > MAX_PHYSICAL_MEMORY)
            break;

        // adding a new_page_dir_entry into page_dir
        page_directory_entry_t* new_page_dir_entry = kmalloc(sizeof(page_directory_entry_t));

        // but first I must create a page_table for it to point to
        page_table_t* new_page_table = kmalloc(sizeof(page_table_t));

        // then initalize everything in the page_table. (right now, just identity match)
        for(j = 0; j < PAGE_TABLE_ENTRIES; j++)
        {
            if(addr > MAX_PHYSICAL_MEMORY)
                break;
            new_page_table->entries[j].addr = addr >> 12; // bc last 12 bits are not stored
            new_page_table->entries[j].user_or_supervisor = 1;
            new_page_table->entries[j].read_or_write = 1;
            new_page_table->entries[j].present = 1;

            addr += 0x1000;
        } 

        // now give new_page_dir_entry some values
        new_page_dir_entry->addr = ((uint32_t) new_page_dir_entry) >> 12;

        // finally place it into page_directory
        page_directory.entries[i] = *new_page_dir_entry;
    }

    set_isr_handler(14, handle_page_fault);

    //assembly move into cr3
    asm volatile("mov %0, %%cr3" :: "r" (&page_directory));

    //set cr0
    uint32_t cr0;
    asm volatile("mov %%cr0, %0" : "=r" (cr0));
    cr0 |= 0x80000000;
    asm volatile("mov %0, %%cr0" :: "r"(cr0));

    printstr("here");
    while(1)
        ;

}
*/