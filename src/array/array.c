/**
 *  @file       array.c
 *  @brief      This file contains the implementations of dynamic array operations.
 *  @author     Duy Tran
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
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
    fprintf(stderr, "Failed to allocate memory. \n");
    return NULL;
}

// ADDING OPERATIONS
/**
 *  @brief      Append an element to the end of the array.
 *
 *  @param      *array      The address to the allocated array.
 *  @param      *data       The address to the data.
 */
void Array_append(Array *array, void *data)
{
    if (array->size == array->capactity)
    {
        Array_resize(array, array->capactity * 2);
    }
    array->elements[array->size++] = data;
}

// REMOVING OPERATIONS

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
        element = array->elements[array->size-1];
    }
    return element; 
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
    assert(array != NULL);
    if (array->size == array->capactity)
    {
        Array_resize(array, array->capactity*2);
    }

    for (int i = array->size; i >= targetIndex; i--)
    {
        array->elements[i+1] = array->elements[i];
    }
    array->elements[targetIndex] = NULL;
    array->size++;
}

void Array_shiftLeft(Array *array, int targetIndex)
{

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
        printf("\n -> Resizing the array to new capacity: %lld - ", newCapacity);
        array->elements = (void **)realloc(array->elements, newCapacity * array->sizeType);
        array->capactity = newCapacity;
        if (array->elements != NULL)
        {
            printf("DONE\n");
        }
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
            else {
                printf("NULL\n");
            }
        }
    }
    else
    {
        printf("Array is empty.\n");
    }
}