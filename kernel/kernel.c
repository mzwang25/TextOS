#include "../drivers/screen.h"
#include "../mlib/print.h"
#include "../mlib/stack32.h"

void main()
{
    clear_screen();
    struct Stack32_char s32;
    stack32_init_char(&s32);
    stack32_push_char(&s32, 'a');
    stack32_push_char(&s32, 'b');
    stack32_push_char(&s32, 'c');


    
}