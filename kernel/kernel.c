#define VIDEO_MEMORY 0xb8000
#include "../drivers/screen.h"

void main()
{
    clear_screen();

    int i = 0;
    for(i = 0; i < 23; i++)
        strprint("Hello this is the Kernel!\n");

    strprint("ATTACK\n");
    strprint("ATTACK\n");
    strprint("ATTACK\n");
    strprint("ATTACK\n");
    strprint("ATTACK\n");
    strprint("ATTACK\n");
    strprint("ATTACK\n");
    strprint("ATTACK\n");
    strprint("ATTACK\n");
    strprint("ATTACK\n");

}