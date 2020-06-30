#ifndef GPIO_H_
#define GPIO_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
void gpio_setDirection(uint32_t base, uint8_t direction);
void gpio_Write(uint32_t base, uint32_t value);
int gpio_Read(uint32_t base);
void gpio_Toggle(uint32_t base);
#ifdef __cplusplus
}
#endif
#endif // GPIO_H_