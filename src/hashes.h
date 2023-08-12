#ifndef HASHES_H
#define HASHES_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "khash/khash.h"

// Sort by value (must be defined after the vectors)

#define KHASH_SORT_BY_VALUE(name, key_type, val_type, val_array_name)                       \
    static key_type *name##_hash_sort_keys_by_value(name##_hash *h, bool reversed) {      \
        size_t n = kh_size(h);                                                              \
        key_type *keys = malloc(sizeof(key_type) * n);                                      \
        val_type *values = malloc(sizeof(val_type) * n);                                    \
                                                                                            \
        size_t i = 0;                                                                       \
        const key_type key;                                                                 \
        val_type value;                                                                     \
        kh_foreach(h, key, value, {                                                         \
            keys[i] = (key_type)key;                                                        \
            values[i] = value;                                                              \
            i++;                                                                            \
        })                                                                                  \
        size_t *sorted_indices = val_array_name##_argsort(values, n);                       \
        key_type *sorted_keys = malloc(sizeof(key_type) * n);                               \
                                                                                            \
        for (i = 0; i < n; i++) {                                                           \
            size_t idx = !reversed ? sorted_indices[i] : sorted_indices[n - i - 1];         \
            sorted_keys[i] = keys[idx];                                                     \
        }                                                                                   \
        free(keys);                                                                         \
        free(values);                                                                       \
        free(sorted_indices);                                                               \
        return sorted_keys;                                                                 \
    }

#define KHASH_NEW(name)                                                                     \
    static name##_hash *name##_hash_new(void) {                                           \
        return kh_init(name);                                                               \
    }

#define KHASH_GET(name, key_type, val_type)                                                                 \
    static bool name##_hash_get(name##_hash *h, key_type key, val_type *val) {                            \
        khiter_t k;                                                                                         \
        k = kh_get(name, h, (const key_type)key);                                                           \
        if (k != kh_end(h)) {                                                                               \
            *val = kh_value(h, k);                                                                          \
            return true;                                                                                    \
        }                                                                                                   \
        return false;                                                                                       \
    }

#define KHASH_PUT(name, key_type, val_type)                                                                 \
    static bool name##_hash_put(name##_hash *h, key_type key, val_type val) {                             \
        int ret = 0;                                                                                        \
        khiter_t k = kh_put(name, h, (const key_type)key, &ret);                                            \
        if (ret < 0) {                                                                                      \
            return false;                                                                                   \
        }                                                                                                   \
        kh_value(h, k) = val;                                                                               \
        return true;                                                                                        \
    }

#define KHASH_DEL(name, key_type, val_type)                                                                 \
    static bool name##_hash_del(name##_hash *h, key_type key) {                                           \
        khiter_t k;                                                                                         \
        k = kh_get(name, h, (const key_type)key);                                                           \
        if (k != kh_end(h)) {                                                                               \
            kh_del(name, h, k);                                                                             \
            return true;                                                                                    \
        }                                                                                                   \
        return false;                                                                                        \
    }

#define KHASH_SIZE(name, key_type, val_type)                                                                \
    static size_t name##_hash_size(name##_hash *h) {                                                      \
        return kh_size(h);                                                                                  \
    }

#define KHASH_CLEAR(name, key_type, val_type)                                                               \
    static void name##_hash_clear(name##_hash *h) {                                                       \
        kh_clear(name, h);                                                                                  \
    }

#define KHASH_CONTAINS(name, key_type, val_type)                                                            \
    static bool name##_hash_contains(name##_hash *h, key_type key) {                                      \
        khiter_t k;                                                                                         \
        k = kh_get(name, h, (const key_type)key);                                                           \
        if (k != kh_end(h)) {                                                                               \
            return true;                                                                                    \
        }                                                                                                   \
        return false;                                                                                       \
    }

#define KHASH_DESTROY(name, key_type, val_type)                                                              \
    static void name##_hash_destroy(name##_hash *h) {                                                      \
        kh_destroy(name, h);                                                                                 \
    }


#define KHASH_BASE(name, key_type, val_type)    \
typedef khash_t(name) name##_hash;            \
KHASH_NEW(name)                                 \
KHASH_GET(name, key_type, val_type)             \
KHASH_PUT(name, key_type, val_type)             \
KHASH_DEL(name, key_type, val_type)             \
KHASH_SIZE(name, key_type, val_type)            \
KHASH_CLEAR(name, key_type, val_type)           \
KHASH_CONTAINS(name, key_type, val_type)        \
KHASH_DESTROY(name, key_type, val_type)


#define KHASH_STR_INCR(name, val_type)                                                                      \
    static bool name##_hash_incr_by_exists(name##_hash *h, const char *key, val_type val, bool *exists) { \
        khiter_t k;                                                                                         \
        int ret = 0;                                                                                        \
        k = kh_get(name, h, key);                                                                           \
        if (k == kh_end(h)) {                                                                               \
            char *key_copy = strdup(key);                                                                   \
            if (key_copy == NULL) {                                                                         \
                return false;                                                                               \
            }                                                                                               \
            k = kh_put(name, h, key_copy, &ret);                                                            \
            if (ret < 0) {                                                                                  \
                free(key_copy);                                                                             \
                return false;                                                                               \
            }                                                                                               \
            kh_value(h, k) = (val_type)0;                                                                   \
            *exists = false;                                                                                \
        } else {                                                                                            \
            *exists = true;                                                                                 \
        }                                                                                                   \
        kh_value(h, k) += val;                                                                              \
        return true;                                                                                        \
    }                                                                                                       \
    static bool name##_hash_incr_exists(khash_t(name) *h, const char *key, bool *exists) {                  \
        return name##_hash_incr_by_exists(h, key, (val_type)1, exists);                                     \
    }                                                                                                       \
    static bool name##_hash_incr_by(khash_t(name) *h, const char *key, val_type val) {                      \
        bool exists = false;                                                                                \
        return name##_hash_incr_by_exists(h, key, val, &exists);                                            \
    }                                                                                                       \
    static bool name##_hash_incr(khash_t(name) *h, const char *key) {                                       \
        bool exists = false;                                                                                \
        return name##_hash_incr_by_exists(h, key, (val_type)1, &exists);                                    \
    }

#define KHASH_STR_TO_ID(name, val_type)                                                                     \
    static bool name##_hash_to_id_exists(name##_hash *h, const char *key, val_type *val, bool *exists) {  \
        khiter_t k;                                                                                         \
        int ret = 0;                                                                                        \
        k = kh_get(name, h, key);                                                                           \
        if (k == kh_end(h)) {                                                                               \
            char *key_copy = strdup(key);                                                                   \
            val_type new_id = (val_type)kh_size(h);                                                         \
            if (key_copy == NULL) {                                                                         \
                return false;                                                                               \
            }                                                                                               \
            k = kh_put(name, h, key_copy, &ret);                                                            \
            if (ret < 0) {                                                                                  \
                free(key_copy);                                                                             \
                return false;                                                                               \
            }                                                                                               \
            kh_value(h, k) = new_id;                                                                        \
            *val = new_id;                                                                                  \
            *exists = false;                                                                                \
            return true;                                                                                    \
        } else {                                                                                            \
            *exists = true;                                                                                 \
        }                                                                                                   \
        *val = kh_value(h, k);                                                                              \
        return true;                                                                                        \
    }                                                                                                       \
    static bool name##_hash_to_id(name##_hash *h, const char *key, val_type *val) {                       \
        bool exists = false;                                                                                \
        if (!name##_hash_to_id_exists(h, key, val, &exists)) {                                              \
            return false;                                                                                   \
        };                                                                                                  \
        return exists;                                                                                      \
    }

#define KHASH_INCR(name, key_type, val_type)                                                                \
    static bool name##_hash_incr_by_exists(name##_hash *h, key_type key, val_type val, bool *exists) {    \
        khiter_t k;                                                                                         \
        int ret = 0;                                                                                        \
        k = kh_get(name, h, key);                                                                           \
        if (k == kh_end(h)) {                                                                               \
            k = kh_put(name, h, key, &ret);                                                                 \
            if (ret < 0) {                                                                                  \
                return false;                                                                               \
            }                                                                                               \
            kh_value(h, k) = (val_type)0;                                                                   \
            *exists = false;                                                                                \
        } else {                                                                                            \
            *exists = true;                                                                                 \
        }                                                                                                   \
        kh_value(h, k) += val;                                                                              \
        return true;                                                                                        \
    }                                                                                                       \
    static bool name##_hash_incr_exists(name##_hash *h, key_type key, bool *exists) {                     \
        return name##_hash_incr_by_exists(h, key, (val_type)1, exists);                                     \
    }                                                                                                       \
    static bool name##_hash_incr_by(name##_hash *h, key_type key, val_type val) {                         \
        bool exists = false;                                                                                \
        return name##_hash_incr_by_exists(h, key, val, &exists);                                            \
    }                                                                                                       \
    static bool name##_hash_incr(name##_hash *h, key_type key) {                                          \
        bool exists = false;                                                                                \
        return name##_hash_incr_by_exists(h, key, (val_type)1, &exists);                                    \
    }

#endif
