#ifndef HASH_STR_DOUBLE_H
#define HASH_STR_DOUBLE_H

#include "hashes.h"
#include "str_sort.h"
#include "num_arrays/double_array.h"

KHASH_MAP_INIT_STR(str_double, double)
KHASH_SORT_BY_VALUE(str_double, char *, double, double_array)
KHASH_STR_INCR(str_double, double)

#endif