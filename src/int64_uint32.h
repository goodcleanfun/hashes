#ifndef HASH_INT64_UINT32_H
#define HASH_INT64_UINT32_H

#include "hashes.h"

KHASH_MAP_INIT_INT64(int64_uint32, uint32_t)
KHASH_INCR(int64_uint32, khint64_t, uint32_t)

#endif