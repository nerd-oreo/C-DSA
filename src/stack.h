#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct ArrayStack
{
    size_t size;
    int top;
    void *stack[MAX_SIZE];
} ArrayStack;

// ArrayStack operations
ArrayStack *ArrayStack_init();
void ArrayStack_push(ArrayStack *stack, void *data);
void *ArrayStack_pop(ArrayStack *stack);
void *ArrayStack_peek(ArrayStack *stack);
void ArrayStack_clear(ArrayStack *stack);
bool ArrayStack_isEmpty(ArrayStack *stack);
bool ArrayStack_isFull(ArrayStack *stack);
void ArrayStack_debug(ArrayStack *stack); // print stack info
#undef STACK_H
#endif
