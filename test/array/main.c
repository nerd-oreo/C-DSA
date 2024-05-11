#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <common/common.h>
#include <array/array.h>

int main()
{
    srand(time(NULL));
    size_t capacity = 20;
    int test_time = 16;

    // Initialize array
    Array *array = Array_init(capacity, sizeof(int*));

    // Test Array_debug()
    Array_debug(array, 'i');

    // Add data to array
    for (int i = 0; i < test_time; i++)
    {
        int *data = (int*) malloc(sizeof(int));
        *data = random_number(1, 500);
        Array_append(array, data);
    }

    // Print array data
    Array_debug(array, 'i');
}