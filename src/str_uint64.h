#ifndef HASH_STR_UINT32_H
#define HASH_STR_UINT32_H

#include "hashes.h"
#include "str_sort.h"
#include "num_arrays/uint64_array.h"

KHASH_MAP_INIT_STR(str_uint64, uint64_t)
KHASH_BASE(str_uint64, char *, uint64_t)
KHASH_SORT_BY_VALUE(str_uint64, char *, uint64_t, uint64_array)
KHASH_STR_INCR(str_uint64, uint64_t)
KHASH_STR_TO_ID(str_uint64, uint64_t)

#endif