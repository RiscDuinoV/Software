#ifndef MTIME_H_
#define MTIME_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
uint64_t getMTIME();
void setMTIMECMP(uint64_t val);
uint64_t getMTIMECMP();
void delay_ms(uint32_t ms);
void delay_us(uint32_t us);
#ifdef __cplusplus
}
#endif
#endif /* MTIME_H_ */