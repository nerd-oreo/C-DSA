/*  @file       array.h
 *  @brief      This file declare the interface for dynamic array data structure.
 *  @author     Duy Tran
 */
#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>

typedef struct Array
{
    void *elements;
    size_t capactity; // Available memory
    size_t size;      // Actual size with data
} Array;

Array * Array_init(size_t capactity, size_t sizeType);

// Adding operations
void Array_append(Array *array, void *data);              // Add last
void Array_prepend(Array *array, void *data);             // Add first
void Array_insertAt(Array *array, int index, void *data); // Insert data at a specifc index

// Removing operations
void Array_removeFirst(Array *array);
void Array_removeLast(Array *array);
void Array_removeAt(Array *array, int index);

// Accessing operations
void * Array_get(Array *array, int index);
void * Array_getFirst(Array *array);
void * Array_getLast(Array *array);

// Shifting
void Array_shiftLeft(Array *array);
void Array_shiftRight(Array *array);

// Size and Capacity operations
size_t Array_size(Array *array);
size_t Array_capacity(Array *array);
void Array_resize(Array *array, size_t newSize);

// Search and Update operations
int Array_search(Array *array, void *value);    // Return value index

// Sort Operations
void Array_sort(Array *array);

// Other operations
void Array_clear(Array *array);
void Array_debug(Array *array);
#endif // ARRAY_H