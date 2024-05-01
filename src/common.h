#ifndef COMMON_H
#define COMMON_H

#define PRNG srand(time(NULL))

int random_int(int min, int max);

#undef COMMON_H
#endif