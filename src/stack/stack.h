#ifndef STACK_H
#define STACK_H

#define INCREASE_SIZE 5
#define TRUE 1
#define FALSE 0

typedef struct Stack {
    int top;
    size_t size;
    void* data; 
} Stack;

Stack* Stack_init(size_t stack_size, size_t type_size);
void Stack_push(Stack* stack, void* data);
void* Stack_pop(Stack* stack);
int Stack_isFull(Stack* stack);
int Stack_isEmpty(Stack* stack);
void* Stack_top(Stack* stack);
Stack* Stack_resize(Stack* stack);

#undef STACK_H
#endif