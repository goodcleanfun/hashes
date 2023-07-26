#ifndef HASH_UINT32_FLOAT_H
#define HASH_UINT32_FLOAT_H

#include "hashes.h"

KHASH_MAP_INIT_INT(uint32_float, float)
KHASH_BASE(uint32_float, khint32_t, float)
KHASH_INCR(uint32_float, khint32_t, float)

#endif