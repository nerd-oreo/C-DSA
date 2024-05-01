#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// Initialize the stack
Stack* Stack_init(size_t stack_size, size_t type_size) {
    printf("Initialize a new stack.\n");
    Stack* stack = malloc(sizeof(Stack));
    if (stack != NULL) {
        printf("Memory allocated.\n");
        stack->size = stack_size;
        stack->top = -1;    // hold the index of the top element, increase by 1 when data is added into the stack
        stack->data = malloc(stack_size * type_size);
        if (stack->data == NULL) {
            fprintf(stderr, "Allocation Error: Failed to allocate memory for stack->data.\n");
            free(stack);
            return NULL;
        }
        printf("A new stack has been created.\n");
    }
    return stack;
}

// Push data into the stack
void Stack_push(Stack* stack, void* data, size_t type_size) {
    printf("Push %d to the stack.\n", *(int*)data);

    if (Stack_isFull(stack)) {
        stack = Stack_resize(stack);
    }
    stack->top++;
    size_t offset = stack->top + type_size;
    void* location = (char*)stack->data + offset;
    memcpy(location, (char*) data, type_size);
    Stack_print(stack);
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
    return stack->top == (stack->size - 1);
}

int Stack_isEmpty(Stack* stack) {
    return stack->top == -1;
}

void* Stack_top(Stack* stack) {
    //return stack->data[stack->top];
    return NULL;
}

Stack* Stack_resize(Stack* stack) {
    // increase the stack size by 5 elements
    return (Stack*)realloc(stack, (stack->size + INCREASE_SIZE) * sizeof(Stack)); 
}

void Stack_print(Stack* stack) {
    if (stack != NULL) {
        printf("\n");
        printf("Size: %ld\n", stack->size);
        printf("Element Count: %ld\n", stack->size-1);
        printf("Top Index: %d\n", stack->top);
        printf("\n");
        if (stack->data != NULL) {
            for (int i = 0; i < stack->size; i++) {
                printf("stack[%d]: %d\n", i, stack->data[i]);
            }
        }
    } else {
        fprintf(stderr, "Stack Error: stack cannot be NULL.\n");
    }
}