#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

int main()
{
    ArrayStack *stack = ArrayStack_init();

    ArrayStack_debug(stack);

    return 0;
}
