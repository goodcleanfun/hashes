#ifndef HASH_UINT64_DOUBLE_H
#define HASH_UINT64_DOUBLE_H

#include "hashes.h"

KHASH_MAP_INIT_INT64(uint64_double, double)
KHASH_BASE(uint64_double, khint64_t, double)
KHASH_INCR(uint64_double, khint64_t, double)

#endif