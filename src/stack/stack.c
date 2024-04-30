#include <stdlib.h>
#include "stack.h"

// Initialize the stack
Stack* Stack_init(size_t stack_size, size_t type_size) {
    Stack* stack = malloc(sizeof(Stack));
    if (stack != NULL) {
        stack->size = stack_size;
        stack->top = -1;    // hold the index of the top element, increase by 1 when data is added into the stack
        stack->data = malloc(stack_size * type_size);
        if (stack->data) {
            free(stack);
            return NULL;
        }
    }
    return stack;
}

void Stack_push(Stack* stack, void* data) {
    if (Stack_isFull(stack) == TRUE) {
        stack = Stack_resize(stack);
    }
    stack->top++;
    //stack->data[stack->top] = data;
}

void* Stack_pop(Stack* stack) {
    if (Stack_isEmpty(stack) != FALSE) {
        //void* data = (void*) stack->data[stack->top];
        stack->top--;
        //return data;
    }
    return NULL;
}

int Stack_isFull(Stack* stack) {
    if ((stack->top + 1) == stack->size)
        return TRUE;
    return FALSE;
}

int Stack_isEmpty(Stack* stack) {
    if (stack->top == -1)
        return TRUE;    // stack is empty
    return FALSE;
}

void* Stack_top(Stack* stack) {
    //return stack->data[stack->top];
}

Stack* Stack_resize(Stack* stack) {
    // increase the stack size by 5 elements
    return (Stack*)realloc(stack, (stack->size + INCREASE_SIZE) * sizeof(Stack)); 
}