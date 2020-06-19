#include "../drivers/screen.h"
#include "print.h"
#include "stack32.h"

// Hopefully I can expand this to print other bases besides 10 with the flags variable
void printint(int num)
{
    struct Stack32_char s32;
    stack32_init_char(&s32);

    int digit;
    while(num != 0)
    {
        digit = num % 10;
        stack32_push_char(&s32, digit + '0');
        num /= 10;
    }

    while(s32.size != 0)
    {
        print_char(stack32_pop_char(&s32));
    }
}

void printstr(char* str)
{
    strprint(str);
}