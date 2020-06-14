#ifndef STACK32_H
#define STACK32_H

#include "types.h"

/*
 * Right now I don't have memory management set up and also don't have the heap.
 * So Stack32 is implemented with a 32 element long array. Also to simulate having
 * templates in C, I will try to use macros for all data types ... or maybe eventually
 */ 

/* Template Code for definition / Implementation */
#define STACK32_DEF(type) \
struct Stack32_##type \
{ \
    type data[32];\
    type* top;\
    int size;\
};\
\
void stack32_init_##type (struct Stack32_##type* stack32ptr);\
int stack32_push_##type (struct Stack32_##type* stack32ptr, type element);\
type stack32_pop_##type (struct Stack32_##type* stack32ptr);



#define STACK32_IMP(type) \
void stack32_init_##type (struct Stack32_##type* stack32ptr)\
{\
    (stack32ptr->size) = 0;\
    (stack32ptr->top) = 0;\
}\
\
/*Push an element into the stack if it's not already full*/\
int stack32_push_##type (struct Stack32_##type* stack32ptr, type element)\
{\
    if(stack32ptr->size < 32)\
    {\
        (stack32ptr->data)[(stack32ptr->size)++] = element;\
        stack32ptr->top = stack32ptr->data + stack32ptr->size - 1;\
        return 0;\
    }\
    else\
    {\
        /*stack is full*/\
        return -1;\
    }\
}\
\
type stack32_pop_##type (struct Stack32_##type* stack32ptr)\
{\
    if(stack32ptr->size != 0)\
    {\
        (stack32ptr->size)--;\
        (stack32ptr->top)--;\
        return *(stack32ptr->top + 1);\
    }\
    else /*size is empty*/\
    {\
        return 0; /*might cause problems since 0 is a valid member*/\
    }\
}

/* Here is the declaration of STACK32 for different data types */

STACK32_DEF(int)
STACK32_DEF(char)
STACK32_DEF(uint8_t)
STACK32_DEF(uint16_t)

#endif
