#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <common/common.h>
#include <array/array.h>

int main()
{
    srand(time(NULL));
    size_t capacity = 10;
    int test_time = 16;

    // Initialize array
    printf("Test Array_init(): ");
    Array *array = Array_init(capacity, sizeof(int *));
    if (array != NULL) { printf("PASS\n"); }

    // Test Array_debug()
    Array_debug(array, 'i');

    // Add data to array
    for (int i = 0; i < test_time; i++)
    {
        int *data = (int *)malloc(sizeof(int));
        *data = random_number(1, 500);
        Array_append(array, data);
    }

    // Print array data
    Array_debug(array, 'i');

    printf("\n");
    printf("Test Array_get():\n");
    int index = 12;
    void *data = Array_get(array, index);
    printf("Value at index %d: %d\n", index, *(int*)data);
    index = 4;
    data = Array_get(array, index);
    printf("Value at index %d: %d\n", index, *(int*)data);
    
    printf("\n");
    printf("Test Array_getFirst():\n");
    data = Array_getFirst(array);
    printf("First element value: %d\n", *(int*)data);

    printf("\n");
    printf("Test Array_getLast():\n");
    data = Array_getLast(array);
    printf("Last element value: %d\n", *(int*)data);

    printf("\n");
    printf("Test Array_shiftRight");
    int targetIndex = 0;
    Array_shiftRight(array, targetIndex);
    Array_debug(array, 'i');
}