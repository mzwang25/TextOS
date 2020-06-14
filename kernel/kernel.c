#define VIDEO_MEMORY 0xb8000
#include "../drivers/screen.h"

void main()
{
    clear_screen();
    strprint("Hello this is the Kernel!\n");
    strprint("Hello this is the Kernel!\n");
    strprint("Hello this is the Kernel!\n");
    strprint("Hello this is the Kernel!\n");
    strprint("Hello this is the Kernel!\n");
    strprint("Hello this is the Kernel!\n");
    strprint("Hello this is the Kernel!\n");
    strprint("Hello this is the Kernel!\n");
    strprint("Hello this is the Kernel!\n");
    strprint("Hello this is the Kernel!\n");

    scroll_up();
    scroll_up();
    scroll_up();
    scroll_up();
    scroll_up();
}
