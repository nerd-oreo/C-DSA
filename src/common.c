#include <stdlib.h>
#include "common.h"

int random_number(int min, int max)
{
    return rand() % (((max + 1) - min) + min);
}