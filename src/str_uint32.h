#ifndef HASH_STR_UINT32_H
#define HASH_STR_UINT32_H

#include "hashes.h"
#include "str_sort.h"
#include "num_arrays/uint32_array.h"

KHASH_MAP_INIT_STR(str_uint32, uint32_t)
KHASH_BASE(str_uint32, char *, uint32_t)
KHASH_SORT_BY_VALUE(str_uint32, char *, uint32_t, uint32_array)
KHASH_STR_INCR(str_uint32, uint32_t)
KHASH_STR_TO_ID(str_uint32, uint32_t)

#endif