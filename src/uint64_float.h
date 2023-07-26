#ifndef HASH_UINT64_FLOAT_H
#define HASH_UINT64_FLOAT_H

#include "hashes.h"

KHASH_MAP_INIT_INT64(uint64_float, float)
KHASH_BASE(uint64_float, khint64_t, float)
KHASH_INCR(uint64_float, khint64_t, float)

#endif