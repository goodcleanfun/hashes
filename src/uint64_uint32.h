#ifndef HASH_UINT64_UINT32_H
#define HASH_UINT64_UINT32_H

#include "hashes.h"

KHASH_MAP_INIT_INT64(uint64_uint32, uint32_t)
KHASH_BASE(uint64_uint32, khint64_t, uint32_t)
KHASH_INCR(uint64_uint32, khint64_t, uint32_t)

#endif