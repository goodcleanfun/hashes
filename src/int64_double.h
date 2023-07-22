#ifndef HASH_INT64_DOUBLE_H
#define HASH_INT64_DOUBLE_H

#include "hashes.h"

KHASH_MAP_INIT_INT64(int64_double, double)
KHASH_BASE(int64_double, khint64_t, double)
KHASH_INCR(int64_double, khint64_t, double)

#endif