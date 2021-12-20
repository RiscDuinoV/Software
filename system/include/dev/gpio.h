#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
#include "dev/io.h"
#define GPIO_INPUT  0
#define GPIO_OUTPUT 1
#define GPIO_HIGH   1
#define GPIO_LOW    0
void gpio_set_direction(uint32_t base, int direction);
void gpio_write(uint32_t base, int value);
int gpio_read(uint32_t base);
void gpio_toggle(uint32_t base);
#ifdef __cplusplus
}
#endif
#endif // GPIO_H