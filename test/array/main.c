#include <stdio.h>
#include <common/common.h>
#include <array/array.h>

int main()
{
    size_t capacity = 20;
    int test_time = 16;

    // Initialize array
    Array *array = Array_init(capacity, sizeof(int));

    // Test Array_debug()
    Array_debug(array, 'i');
}