#ifndef HASH_INT_UINT32_H
#define HASH_INT_UINT32_H

#include "hashes.h"

KHASH_MAP_INIT_INT(int_uint32, uint32_t)
KHASH_BASE(int_uint32, khint32_t, uint32_t)
KHASH_INCR(int_uint32, khint32_t, uint32_t)

#endif