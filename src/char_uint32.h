#ifndef HASH_CHAR_UINT32_H
#define HASH_CHAR_UINT32_H

#define kh_char_hash_func(key) (uint32_t)(key)
#define kh_char_hash_equal(a, b) ((a) == (b))

KHASH_INIT(char_uint32, char, uint32_t, 1, kh_char_hash_func, kh_char_hash_equal)
KHASH_INIT(uchar_uint32, unsigned char, uint32_t, 1, kh_char_hash_func, kh_char_hash_equal)

#endif