#ifndef CRYPTONIGHT_H
#define CRYPTONIGHT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void cn_slow_hash(const void *data, size_t length, char *hash, int variant, int prehashed, uint64_t height = 0);

#ifdef __cplusplus
}
#endif

#endif
