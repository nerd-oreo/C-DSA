/*  @file       array.c
 *  @brief      This file contains the implementations of dynamic array operations.
 *  @author     Duy Tran
 */
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/*  @brief      Initialize new array
*   @param      capacity The number of elements the array can hold.
*   @param      typeSize Size of the data type that being stored in the array.
*   @return     Return the address to the new array
*/
Array * Array_init(size_t capacity, size_t sizeType)
{
    Array *array = (Array*) malloc(sizeof(Array));
    if (array != NULL)
    {
        array->elements = malloc(capacity * sizeType);
        array->capactity = capacity;
        array->size = 0;
        return array;
    }
    fprintf(stderr, "Failed to allocate memory. \n");
    return NULL;
}