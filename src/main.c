#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    for (int i = 0; i < nItem; i++)
    {
        int *data = (int*) malloc(sizeof(int));
        *data = random_number(1, 100);
        ArrayStack_push(stack, data);
    }

    ArrayStack_debug(stack, 'i');
}