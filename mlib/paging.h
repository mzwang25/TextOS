#ifndef PAGING_H 
#define PAGING_H

#include "types.h"
#include "../cpu/isr.h"

typedef struct page 
{
    uint32_t present : 1;
    uint32_t rw : 1;
    uint32_t user : 1;
    uint32_t accessed : 1;
    uint32_t dirty : 1;
    uint32_t unused : 7;
    uint32_t frame : 20;

} page_t;

typedef struct page_table
{
    page_t pages[1024];
} page_table_t;

typedef struct page_directory
{
    // Array of pointers to pagetables
    page_table_t* tables[1024];

    // Pointers to pagetables but with physical location
    uint32_t tablesPhysical[1024];

    //physical address of tablesPhysical
    uint32_t physicalAddr;
} page_directory_t;

// Sets up Paging
void initialize_paging();

// Loads new page directory into CR3 Register
void switch_page_directory(page_directory_t* new_page_dir);

// Gets pointer to page ... if(make) -> create page-table if it dosen't exist
page_t* get_page(uint32_t address, int make, page_directory_t* dir);

// Handler for page faults
void page_fault(registers_t regs);

#endif