#include <stdio.h>
#include "stack.h"

ArrayStack *ArrayStack_init()
{
    ArrayStack *stack = (ArrayStack *)malloc(sizeof(ArrayStack)); // by default malloc would return void*
    if (stack != NULL)
    {
        stack->size = 0;
        stack->top = -1; // top index increase by 1 whenever new data is pushed to the stack
        return stack;
    }
    return NULL; // fail to allocate memory
}