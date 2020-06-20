#ifndef PAGING_H
#define PAGING_H

#include "types.h"

#define PAGE_TABLE_ENTRIES 1024
#define PAGE_DIR_ENTRIES 1024
#define MAX_PHYSICAL_MEMORY 0x10000000



void initialize_paging();


#endif