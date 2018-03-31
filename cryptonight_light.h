#ifndef CRYPTONIGHT_LIGHT_H
#define CRYPTONIGHT_LIGHT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void cn_light_slow_hash(const void *data, size_t length, char *hash, int light, int variant);

#ifdef __cplusplus
}
#endif

#endif
