#ifndef _SIO_H_
#define _SIO_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
int sio_available(uint32_t base);
int sio_getch(uint32_t base);
int sio_putchar(uint32_t base, int c);
int sio_puts(uint32_t base, const char *str);
int sio_print_number(uint32_t base, uint32_t n, int base_print);
int sio_print_float(uint32_t base, float number, int digits);
int sio_print_double(uint32_t base, double number, int digits);
void sio_set_baud(uint32_t base, uint32_t baud);
#ifdef __cplusplus
}
#endif
#endif /* _SIO_H_ */