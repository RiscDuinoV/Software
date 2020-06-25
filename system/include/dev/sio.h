#ifndef _SIO_H_
#define _SIO_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
uint8_t sio_available(uint32_t base);
uint8_t sio_getch(uint32_t base);
int sio_putchar(uint32_t base, const uint8_t c);
int sio_puts(uint32_t base, const char *str);
int sio_printNumber(uint32_t base, unsigned long n, uint8_t base_print);
int sio_printFloat(uint32_t base, double number, uint8_t digits);
 
#ifdef __cplusplus
}
#endif
#endif /* _SIO_H_ */