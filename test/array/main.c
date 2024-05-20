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
    if (array != NULL)
    {
        printf("PASS\n");
    }

    // Test Array_debug()
    Array_debug(array, 'i');

    // Add data to array
    for (int i = 0; i < test_time; i++)
    {
        // int *data = (int *)malloc(sizeof(int));
        //*data = random_number(1, 500);
        int data = random_number(1, 500);
        Array_append(array, &data);
    }

    // Print array data
    Array_debug(array, 'i');

    printf("\n");
    printf("Test Array_get():\n");
    int index = 12;
    void *data = Array_get(array, index);
    printf("Value at index %d: %d\n", index, *(int *)data);
    index = 4;
    data = Array_get(array, index);
    printf("Value at index %d: %d\n", index, *(int *)data);

    printf("\n");
    printf("Test Array_getFirst():\n");
    data = Array_getFirst(array);
    printf("First element value: %d\n", *(int *)data);

    printf("\n");
    printf("Test Array_getLast():\n");
    data = Array_getLast(array);
    printf("Last element value: %d\n", *(int *)data);

    printf("\n");
    printf("Test Array_prepend");
    int newData = 5;
    Array_prepend(array, &newData);
    Array_debug(array, 'i');

    printf("\n");
    printf("Test Array_insertAdd");
    newData = 1000;
    Array_insertAt(array, 5, &newData);
    Array_debug(array, 'i');

    printf("\n");
    printf("Test Array_insertAdd");
    newData = 2000;
    Array_insertAt(array, Array_size(array), &newData);
    Array_debug(array, 'i');

    printf("\n");
    printf("Test Array_insertAdd");
    newData = random_number(1, 2000);
    Array_insertAt(array, Array_size(array), &newData);
    Array_debug(array, 'i');

    printf("\n");
    printf("Test Array_insertAdd");
    newData = random_number(1, 2000);
    Array_insertAt(array, Array_size(array), &newData);
    Array_debug(array, 'i');

    printf("\n");
    printf("Test Array_push");
    newData = random_number(1, 2000);
    Array_push(array, &newData);
    Array_debug(array, 'i');

    printf("\n");
    printf("Test Array_top");
    void *topElement = Array_top(array);
    printf("Top Element = %d\n", *(int *)topElement);

    printf("\n");
    printf("Test Array_shiftLeft");
    Array_shiftLeft(array, 0);
    Array_debug(array, 'i');
    Array_shiftLeft(array, 5);
    Array_debug(array, 'i');

    // printf("\n");
    // printf("Test Array_shiftLeft with resize");
    // int shiftTime = 10;
    // for (int i = 0; i < shiftTime; i++)
    // {
    //     Array_shiftLeft(array, 0);
    // }
    // Array_debug(array, 'i');

    printf("\n");
    printf("Test Array_removeFirst");
    void *removedData = Array_removeFirst(array);
    Array_debug(array, 'i');
    printf("\nRemoved element: %d\n", *(int *)removedData);

    printf("\n");
    printf("Test Array_removeLast");
    removedData = Array_removeLast(array);
    Array_debug(array, 'i');
    printf("\nRemoved element: %d\n", *(int *)removedData);

    printf("\n");
    printf("Test Array_removeAt");
    index = 7;
    removedData = Array_removeAt(array, index);
    Array_debug(array, 'i');
    printf("\nRemoved element: %d\n", *(int *)removedData);

    printf("\n");
    printf("Test Array_removeAt - Using loop");
    for (int i = array->size - 1; i >= 0; i--)
    {
        removedData = Array_removeAt(array, i);
        Array_debug(array, 'i');
        printf("\nRemoved element: %d at index %d\n", *(int *)removedData, i);
    }

    return 0;
}