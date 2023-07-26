#ifndef HASH_UINT32_DOUBLE_H
#define HASH_UINT32_DOUBLE_H

#include "hashes.h"

KHASH_MAP_INIT_INT(uint32_double, double)
KHASH_BASE(uint32_double, khint32_t, double)
KHASH_INCR(uint32_double, khint32_t, double)

#endif