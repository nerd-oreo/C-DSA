#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "stack.h"

void stack_test();

int main()
{
    stack_test();

    return 0;
}

void stack_test()
{
    srand(time(NULL));
    int nItem = 5;

    ArrayStack *stack = ArrayStack_init();

    // Add data to the stack


    ArrayStack_debug(stack);
}