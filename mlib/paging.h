#ifndef PAGING_H
#define PAGING_H

#include "types.h"

#define PAGE_TABLE_ENTRIES 1024
#define PAGE_DIR_ENTRIES 1024
#define MAX_PHYSICAL_MEMORY 0x1000000;

/**
 * Page Directory entries are 32 bit
 * They are 4 KiB aligned so last 12
 * bits are always zero. These extra
 * bits are used to store other info
 * */
typedef struct 
{
    uint32_t addr               : 20;
    uint32_t available          :  3;
    uint32_t ignored            :  1;
    uint32_t page_size          :  1;
    uint32_t accessed           :  1;
    uint32_t zero               :  1;
    uint32_t cache_disabled     :  1;
    uint32_t write_through      :  1;
    uint32_t user_or_supervisor :  1;
    uint32_t read_or_write      :  1;
    uint32_t present            :  1;

} page_directory_entry_t;


/* Page Entry: addr is a physical address! */
typedef struct 
{
    uint32_t addr               : 20;
    uint32_t available          :  1;
    uint32_t global             :  1;
    uint32_t zero               :  1;
    uint32_t dirty              :  1;
    uint32_t accessed           :  1;
    uint32_t cache_disabled     :  1;
    uint32_t write_through      :  1;
    uint32_t user_or_supervisor :  1;
    uint32_t read_or_write      :  1;
    uint32_t present            :  1;

} page_table_entry_t;

page_table_entry_t* page_table[PAGE_TABLE_ENTRIES];
page_directory_entry_t* page_dir[PAGE_DIR_ENTRIES];

void initialize_paging();


#endif