#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>

typedef struct Array
{
    void *elements;
    size_t capactity; // Available memory
    size_t size;      // Actual size with data
} Array;

Array *Array_init(size_t capactity);

// Adding operations
void Array_append(Array *array, void *data);              // Add last
void Array_prepend(Array *array, void *data);             // Add first
void Array_insertAt(Array *array, int index, void *data); // Insert data at a specifc index

// Removing operations
void Array_removeFirst(Array *array);
void Array_removeLast(Array *array);
void Array_removeAt(Array *array, int index);

// Accessing operations

// Size and Capacity operations

// Search and Update operations

// Sort Operations

// Resizing operations
void Array_resize(Array *array, size_t new_size);

// Other operations
void Array_clear(Array *array);

#endif