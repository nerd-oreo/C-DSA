#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* Stack_init(size_t stack_size, size_t type_size) {
    Stack *stack = malloc(sizeof(Stack));
    stack->size = stack_size;
    stack->top = 0;
    stack->data = malloc(stack_size * type_size);
}