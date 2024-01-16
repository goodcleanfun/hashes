#ifndef HASH_UINT32_UINT64_H
#define HASH_UINT32_UINT64_H

#include "hashes.h"

KHASH_MAP_INIT_INT(uint32_uint64, uint64_t)
KHASH_BASE(uint32_uint64, khint32_t, uint64_t)
KHASH_INCR(uint32_uint64, khint32_t, uint64_t)

#endif
