#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* create_array(size_t array_size, size_t type_size);
void add_data(int* array, size_t array_size);
void print_array(int* array, size_t array_size);
int random_number(int min, int max);

int main() {
    srand(time(NULL));
    size_t array_size = 5;

    void* arr = create_array(array_size, sizeof(int));
    add_data((int*) arr, array_size);
    print_array((int*) arr, array_size);

    return 0;
}

void* create_array(size_t array_size, size_t type_size) {
    void* arr = malloc(array_size * type_size);
    return arr;
}

void add_data(int* array, size_t array_size) {
    for (int i = 0; i < array_size; i++) {
        array[i] = random_number(1, 100);
    }
}

void print_array(int* array, size_t array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("array[%d]: %d\n", i, array[i]);
    }
}

int random_number(int min, int max) {
    return rand() % (((max + 1) - min) + min);
}