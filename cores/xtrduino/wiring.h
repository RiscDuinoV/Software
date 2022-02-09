#ifndef WIRING_H_
#define WIRING_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "riscv/mtime.h"
uint64_t millis(void);
uint64_t micros(void);
#ifdef __cplusplus
}
#endif
#endif // WIRING_H_