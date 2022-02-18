#ifndef MTIME_H_
#define MTIME_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#ifndef F_CPU
#error "You must define CPU frequency as a macro!"
#endif
#define MS		(uint32_t)(1e-3 * F_CPU)
#define US      (uint32_t)(1e-6 * F_CPU)
#define TICKS_TO_MS(ticks) (ticks * (uint32_t)(1e3) / (uint32_t)F_CPU)
#define TICKS_TO_US(ticks) (ticks * (uint32_t)(1e6) / (uint32_t)F_CPU)
#define MS_TO_TICKS(ms) (ms * (uint32_t)(F_CPU / 1e3))
#define US_TO_TICKS(us) (us * (uint32_t)(F_CPU / 1e6))
uint64_t get_mtime();
void set_mtime_cmp(uint64_t val);
uint64_t get_mtime_cmp();
void delay_ms(uint32_t ms);
void delay_us(uint32_t us);
#define delay(ms)   delay_ms(ms)
#define delayMicroseconds(us) delay_us(us)
#ifdef __cplusplus
}
#endif
#endif /* MTIME_H_ */