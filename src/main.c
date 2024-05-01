#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

int random_number(int min, int max);


int main() {
    srand(time(NULL));
    const size_t stack_size = 5;

    int test_1 = 5;

    // Initialize the stack
    Stack *stack = Stack_init(stack_size, sizeof(int));

    // Check if the stack is empty
    if (stack != NULL) {
        printf("Stack is empty: %d\n", Stack_isEmpty(stack));
        
        // Push data to the stack
        for (int i = 0; i < test_1; i++) {
            int number = random_number(1, 100);
            int* num_ptr = &number;
            Stack_push(stack, (void*)num_ptr, sizeof(int));
        }

    }

    // Check if the stack is full

    // Resize the stack

    // Push more data into the stack
    
    // Read the top element of the stack

    // Pop and read data from the stack

    return 0;
}

int random_number(int min, int max) {
    return rand() % (((max + 1) - min) + min);
}