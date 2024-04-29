#ifndef STACK_H
#define STACK_H

#define DEFAULT_SIZE 5

struct Stack {
    int top;
    int size;
    void *data; 
};

typedef Stack Stack;
Stack* Stack_init(int size);
void Stack_push(void *data);
void* Stack_pop(Stack *stack);
int Stack_isFull(Stack *stack);
int Stack_isEmpty(Stack *stack);
void* Stack_top(Stack *stack);

#undef STACK_H
#endif