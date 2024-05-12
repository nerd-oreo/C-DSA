#include <stdlib.h>
#include "common.h"

/**
 * @brief   Generate a random integer between a specified range.
 *
 * @param min   A minimum range number
 * @param max   A maximum range number
 * @return int   Return a random integer
 */
int random_number(int min, int max)
{
    return rand() % (((max + 1) - min) + min);
}