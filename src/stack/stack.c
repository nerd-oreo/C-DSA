/*  @file       stack.c
 *  @brief      This file implements the ArrayStack operations.
 *  @author     Duy Tran
 */
#include <stdio.h>
#include "stack.h"

/*  @brief      Initialize the stack.
 *  @return     Return the address to the stack, or NULL if it fails to allocate memory.
 */
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

/*  @brief      Push data to the stack
 *  @param      [in] stack: The address to the stack.
 *  @param      [in] data:  The address to the data.
 */
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

/*  @brief      Pop data from the stack
 *  @param      [in] stack: The address to the stack.
 *  @return     return the address to the data.
 */
void *ArrayStack_pop(ArrayStack *stack)
{
    if (!ArrayStack_isEmpty(stack))
    {
        void *data = stack->data[stack->top];
        stack->data[stack->top] = NULL;
        stack->top--;
        stack->size--;
        return data;
    }
    fprintf(stderr, "The stack is empty.\n");
    return NULL;
}

/*  @brief      Fetch data from the top of the stack
 *  @param      [in] stack: The address to the stack.
 *  @return     return the address to the data.
 */
void *ArrayStack_peek(ArrayStack *stack)
{
    if (!ArrayStack_isEmpty(stack))
    {
        void *data = stack->data[stack->top];
        return data;
    }
    fprintf(stderr, "The stack is empty.\n");
    return NULL;
}

/*  @brief      Check if the stack is empty.
 *  @param      [in] stack: The address to the stack.
 *  @return     Return true if the stack is empty, false otherwise.
 */
bool ArrayStack_isEmpty(ArrayStack *stack)
{
    return stack->size == 0;
}

/*  @brief      Check if the stack is full.
 *  @param      [in] stack: The address to the stack.
 *  @return     Return true if the stack full, false otherwise.
 */
bool ArrayStack_isFull(ArrayStack *stack)
{
    return stack->top == stack->size - 1;
}

/*  @brief      Print out the stack information and data.
 *  @param      [in] stack: The address to the stack.
 *  @param      [in] type: The data type of the actual data (i: int, c: char, f: float)
 */
void ArrayStack_debug(ArrayStack *stack, char type)
{
    if (stack != NULL)
    {
        printf("\n");
        printf("stack->size: %llu\n", stack->size);
        printf("stack->top: %d\n", stack->top);
        printf("----------------------------------\n");
        // Print the elements from the top
        for (int index = stack->top; index > 0; index--)
        {
            void *data = stack->data[index];
            printf("stack[%d]: ", index);
            switch (type)
            {
            case 'i': // integer
                printf("%d\n", *(int *)data);
                break;
            case 'c':
                printf("%c\n", *(char *)data);
                break;
            case 'f':
                printf("%f\n", *(float *)data);
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