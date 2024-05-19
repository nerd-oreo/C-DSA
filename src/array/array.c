/**
 *  @file       array.c
 *  @brief      This file contains the implementations of dynamic array operations.
 *  @author     Duy Tran
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "array.h"

/**
 *  @brief      Initialize new array
 *
 *  @param      capacity    The number of elements the array can hold.
 *  @param      typeSize    Size of the data type that being stored in the array.
 *  @return     Return the address to the new array
 */
Array *Array_init(size_t capacity, size_t sizeType)
{
    Array *array = (Array *)malloc(sizeof(Array));
    if (array != NULL)
    {
        array->elements = (void **)malloc(capacity * sizeType);
        array->capactity = capacity;
        array->size = 0;
        array->sizeType = sizeType;
        return array;
    }
    fprintf(stderr, "Failed to allocate memory.\n");
    return NULL;
}

// ADDING OPERATIONS
/**
 *  @brief      Append an element to the end of the array.
 *
 *  @param array      The address to the allocated array.
 *  @param data       The address to the data.
 */
void Array_append(Array *array, void *data)
{
    if (array->size == array->capactity)
    {
        Array_resize(array, array->capactity * 2);
    }
    // array->elements[array->size++] = data;
    void *element = malloc(array->sizeType); // allocate memory for a new element
    if (element != NULL)
    {
        memcpy(element, data, array->sizeType);   // copy value from data pointer to the new element
        array->elements[array->size++] = element; // add the new element to the end of the array
    }
    else
    {
        fprintf(stderr, "Failed to allocate memory for the new element.\n");
    }
}

/**
 * @brief           Add new data to the beginning of the array
 *
 * @param array     The address of the array
 * @param data      The address of the data
 */
void Array_prepend(Array *array, void *data)
{
    int firstIndex = 0;
    assert(array != NULL);
    Array_shiftRight(array, firstIndex);

    void *element = malloc(array->sizeType);
    if (element != NULL)
    {
        memcpy(element, data, array->sizeType);
        array->elements[firstIndex] = element;
    }
    else
    {
        fprintf(stderr, "Failed to allocate memory for the new element.\n");
    }
}

/**
 * @brief           Add new element to a specific index
 *
 * @param array     The address of the array
 * @param index     Array index
 * @param data      The address of the data
 */
void Array_insertAt(Array *array, int index, void *data)
{
    if (array != NULL)
    {
        Array_shiftRight(array, index);
        void *element = malloc(array->sizeType);
        if (element != NULL)
        {
            memcpy(element, data, array->sizeType);
            array->elements[index] = element;
        }
        else
        {
            fprintf(stderr, "Failed to allocate memory for the new element.\n");
        }
    }
}

/**
 * @brief           Push the data add the end of the array
 *
 * @param array     The address of the array
 * @param data      The address of the data
 */
void Array_push(Array *array, void *data)
{
    Array_append(array, data);
}

// REMOVING OPERATIONS
/**
 * @brief           Remove the first element in the array
 *
 * @param array     The address of the array
 * @return void*    Return the data stores in the first element
 */
void *Array_removeFirst(Array *array)
{
    void *element = NULL;
    if (array != NULL && !Array_isEmpty(array))
    {
        int firstIndex = 0;
        element = array->elements[firstIndex];
        Array_shiftLeft(array, firstIndex);
    }
    return element;
}

/**
 * @brief           Remove the last element in the array
 *
 * @param array     The address of the array
 * @return void*    Return the data stores in the first element
 */
void *Array_removeLast(Array *array)
{
    void *element = NULL;
    if (array != NULL && !Array_isEmpty(array))
    {
        element = array->elements[--array->size]; // pre-increment operator: --array->size decrease the value of size and return the decremented value
        array->elements[array->size] = NULL;
    }
    return element;
}

// ACCESSING OPERATIONS
/**
 * @brief           Get the element from the array at a specific index
 *
 * @param array     The address of the array
 * @param index     Element index
 * @return void*    Return the address of the element
 */
void *Array_get(Array *array, int index)
{
    void *element = NULL;
    if (array != NULL && !Array_isEmpty(array))
    {
        element = array->elements[index];
    }
    return element;
}

/**
 * @brief           Get the first element from the array
 *
 * @param array     The address to the array
 * @return void*    Return the address of the element
 */
void *Array_getFirst(Array *array)
{
    void *element = NULL;
    if (array != NULL && !Array_isEmpty(array))
    {
        element = array->elements[0];
    }
    return element;
}

/**
 * @brief           Get the last element from the array
 *
 * @param array     The address to the array
 * @return void*    Return the address of the element
 */
void *Array_getLast(Array *array)
{
    void *element = NULL;
    if (array != NULL && !Array_isEmpty(array))
    {
        element = array->elements[array->size - 1];
    }
    return element;
}

/**
 * @brief           Get the element at the top of the stack (the last element in the array)
 *
 * @param array     The address of the array
 * @return void*    Return the address of the element
 */
void *Array_top(Array *array)
{
    return Array_getLast(array);
}

// SHIFTING OPERATIONS
/**
 * @brief               Shift the elements to the right from a specific index
 *
 * @param array         The address of the array
 * @param targetIndex   The target index where the shifting start
 */
void Array_shiftRight(Array *array, int targetIndex)
{
    if (array != NULL)
    {
        if (array->size == array->capactity)
        {
            Array_resize(array, array->capactity * 2);
        }

        for (int i = array->size; i >= targetIndex; i--)
        {
            array->elements[i + 1] = array->elements[i];
        }
        array->elements[targetIndex] = NULL;
        array->size++;
    }
}

/**
 * @brief               Shift the elements to the left from a specific index
 *
 * @param array         The address of the array
 * @param targetIndex   The target index where the shift start
 */
void Array_shiftLeft(Array *array, int targetIndex)
{
    if (array != NULL)
    {
        for (int i = targetIndex; i < array->size; i++)
        {
            array->elements[i] = array->elements[i + 1];
        }
        array->elements[array->size--] = NULL;
        // array->size--;

        if ((array->size * 2) == array->capactity)
        {
            Array_resize(array, array->capactity / 2);
        }
    }
}

// SIZE AND CAPACITY OPERATIONS
/**
 *  @brief          Get the size of the array
 *  @param array    The address of the array
 *  @return         Return the size of the array
 */
size_t Array_size(Array *array)
{
    return array->size;
}

/**
 * @brief           Get the capacity of the array
 *
 * @param array     The address of the array
 * @return size_t   Return the capacity of the array
 */
size_t Array_capacity(Array *array)
{
    return array->capactity;
}

/**
 * @brief               Resize the array
 *
 * @param array         The address to the array
 * @param newCapacity   The new capacity of the array
 */
void Array_resize(Array *array, size_t newCapacity)
{
    if (array != NULL)
    {
        array->elements = (void **)realloc(array->elements, newCapacity * array->sizeType);
        array->capactity = newCapacity;
    }
}

/**
 * @brief           Check if the array is empty
 *
 * @param array     The address of the array
 * @return          Return true if the array is empty, otherwise false.
 */
bool Array_isEmpty(Array *array)
{
    return array->size == 0;
}

// SEARCH OPERATIONS

// SORT OPERATIONS

// OTHER OPERATIONS
/**
 *  @brief              Print array data for debugging purpose.
 *  @param array        The address to the array.
 *  @param dataType     Indicate data type for printing format.
 */
void Array_debug(Array *array, char dataType)
{
    printf("\n");
    printf("Array locates at %p\n", array);
    printf("Array elements locate at %p\n", array->elements);
    printf("Capacity: %lld\n", array->capactity);
    printf("Size: %lld\n", array->size);

    if (array->size > 0)
    {
        printf("-----------------------------\n");
        printf("Array Data:\n");
        for (int i = 0; i < array->size; i++)
        {
            printf("array[%2d]: ", i);
            if (array->elements[i] != NULL)
            {
                switch (dataType)
                {
                case 'i':
                    printf("%d\n", *((int *)array->elements[i]));
                    break;
                case 'c':
                    printf("%c\n", *((char *)array->elements[i]));
                    break;
                case 'f':
                    printf("%f\n", *((float *)array->elements[i]));
                    break;
                default:
                    printf("unspecified\n");
                    break;
                }
            }
            else
            {
                printf("NULL\n");
            }
        }
    }
    else
    {
        printf("Array is empty.\n");
    }
}