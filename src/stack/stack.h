#ifndef STACK_H
#define STACK_H

#define DEFAULT_SIZE 5

struct Stack {
    int top;
    size_t size;
    void *data; 
};

typedef Stack Stack;
Stack* Stack_init(size_t stack_size, size_t type_size);
void Stack_push(void *data);
void* Stack_pop(Stack *stack);
int Stack_isFull(Stack *stack);
int Stack_isEmpty(Stack *stack);
void* Stack_top(Stack *stack);

#undef STACK_H
#endif