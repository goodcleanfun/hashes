#ifndef HASH_UINT32_UINT32_H
#define HASH_UINT32_UINT32_H

#include "hashes.h"

KHASH_MAP_INIT_INT(uint32_uint32, uint32_t)
KHASH_BASE(uint32_uint32, khint32_t, uint32_t)
KHASH_INCR(uint32_uint32, khint32_t, uint32_t)

#endif