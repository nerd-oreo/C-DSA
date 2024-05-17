/**
 *  @file       array.h
 *  @brief      This file declare the interface for dynamic array data structure.
 *  @author     Duy Tran
 */
#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>
#include <stdbool.h>

typedef struct Array
{
    void **elements;  // Using void** (pointer to pointer) to create an array of pointers that can store data addresses instead of data value.
    size_t capactity; // Available memory
    size_t size;      // Actual size with data
    size_t sizeType;  // The size of the data type that stores in the array
} Array;

Array *Array_init(size_t capactity, size_t sizeType);

void Array_append(Array *array, void *data);              // Add last
void Array_prepend(Array *array, void *data);             // Add first
void Array_insertAt(Array *array, int index, void *data); // Insert data at a specifc index
void Array_push(Array *array, void *data);

void Array_removeFirst(Array *array);
void Array_removeLast(Array *array);
void Array_removeAt(Array *array, int index);

void *Array_get(Array *array, int index);
void *Array_getFirst(Array *array);
void *Array_getLast(Array *array);

void Array_shiftLeft(Array *array, int targetIndex);
void Array_shiftRight(Array *array, int targetIndex);

size_t Array_size(Array *array);
size_t Array_capacity(Array *array);
void Array_resize(Array *array, size_t newCapacity);
bool Array_isEmpty(Array *array);

int Array_search(Array *array, void *value); // Return value index

void Array_sort(Array *array);

void Array_clear(Array *array);
void Array_debug(Array *array, char dataType);
#endif // ARRAY_H