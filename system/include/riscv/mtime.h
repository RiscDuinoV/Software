#ifndef MTIME_H_
#define MTIME_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
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