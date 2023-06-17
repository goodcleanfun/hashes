#ifndef HASH_STR_FLOAT_H
#define HASH_STR_FLOAT_H

#include "hashes.h"
#include "str_sort.h"
#include "num_arrays/float_array.h"

KHASH_MAP_INIT_STR(str_float, float)
KHASH_SORT_BY_VALUE(str_float, char *, float, float_array)
KHASH_STR_INCR(str_float, float)

#endif