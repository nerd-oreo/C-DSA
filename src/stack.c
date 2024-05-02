#include <stdio.h>
#include "stack.h"

ArrayStack *ArrayStack_init()
{
    ArrayStack *stack = (ArrayStack *)malloc(sizeof(ArrayStack)); // by default malloc would return void*
    if (stack != NULL)
    {
        stack->size = 0;
        stack->top = 0; // top index increase by 1 whenever new data is pushed to the stack
        return stack;
    }
    return NULL; // fail to allocate memory
}

void ArrayStack_push(ArrayStack *stack, void *data)
{
    if (ArrayStack_isEmpty(stack) || !ArrayStack_isFull(stack))
    {
        stack->top++;
        stack->data[stack->top] = data;
        stack->size++;
    }
    else
    {
        fprintf(stderr, "Stack Error: The stack is full.\n");
    }
}

bool ArrayStack_isEmpty(ArrayStack *stack)
{
    return stack->size == 0;
}

bool ArrayStack_isFull(ArrayStack *stack)
{
    return stack->top == stack->size-1;
}

void ArrayStack_debug(ArrayStack *stack, char type)
{
    if (stack != NULL)
    {
        printf("stack->size: %llu\n", stack->size);
        printf("stack->top: %d\n", stack->top);
        printf("----------------------------------\n\n");
        // Print the elements from the top
        for (int index = stack->top; index > 0; index--)
        {
            void *data = stack->data[index];
            printf("stack[%d]: ", index);
            switch (type)
            {
                case 'i':   // integer
                    printf("%d\n", *(int*)data);
                    break;
                case 'c':
                    printf("%c\n", *(char*)data);
                    break;
                case 'f':
                    printf("%f\n", *(float*)data);
                    break;
                default:
                    printf("unspecified type\n");
                    break;
            }
        }
    }
    else 
    {
        printf("The stack is null.\n");
    }
}