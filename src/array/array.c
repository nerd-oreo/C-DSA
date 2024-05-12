/**
 *  @file       array.c
 *  @brief      This file contains the implementations of dynamic array operations.
 *  @author     Duy Tran
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

/**
 *  @brief      Initialize new array
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
        return array;
    }
    fprintf(stderr, "Failed to allocate memory. \n");
    return NULL;
}

/** ADDING OPERATIONS **/
/**
 *  @brief      Append an element to the end of the array.
 *  @param      *array      The address to the allocated array.
 *  @param      *data       The address to the data.
 */
void Array_append(Array *array, void *data)
{
    if (array->size < array->capactity)
    {
        array->elements[array->size] = data;
        array->size++;
    }
}

/** REMOVING OPERATIONS **/

/** ACCESSING OPERATIONS **/

/** SHIFTING OPERATIONS **/

/** SIZE AND CAPACITY OPERATIONS **/
/**
 *  @brief      Get the size of the array
 *  @param      *array      The address of the array
 *  @return     Return the size of the array
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
 * @brief           Check if the array is empty
 *
 * @param array     The address of the array
 * @return     Return true if the array is empty, otherwise false.
 */
bool Array_isEmpty(Array *array)
{
    return array->size == 0;
}

/** SEARCH OPERATIONS **/

/** SORT OPERATIONS **/

/** OTHER OPERATIONS **/
/**
 *  @brief      Print array data for debugging purpose.
 *  @param      array:      The address to the array.
 *  @param      dataType:   Indicate data type for printing format.
 */
void Array_debug(Array *array, char dataType)
{
    printf("Capacity: %lld\n", array->capactity);
    printf("Size: %lld\n", array->size);

    if (array->size > 0)
    {
        printf("-----------------------------\n");
        printf("Array Data:\n");
        for (int i = 0; i < array->size; i++)
        {
            printf("array[%2d]: ", i);
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
    }
    else
    {
        printf("Array is empty.\n");
    }
}