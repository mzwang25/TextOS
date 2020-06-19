#include "mem.h"

void bzero(void* buff, uint32_t bytes)
{
    //want to loop by bytes
    uint8_t* addr = (uint8_t*) buff;

    int i = 0;
    for(i = 0; i < bytes; i++)
    {
        addr[i] = 0x0;
    }
}