#include "dev/gpio.h"
#include "dev/io.h"
void pinMode(uint8_t pin, uint8_t mode)
{
    uint8_t tmp;
    uint32_t gpio_base = GPIO_BASE + pin*4;
    LB(tmp, 2, gpio_base);
    tmp = (tmp & 0x6) | (mode & 0x1);
    SB(tmp, 2, gpio_base);
}
void digitalWrite(uint8_t pin, uint8_t val)
{
    uint32_t gpio_base = GPIO_BASE + pin*4;
    SB(val, 0, gpio_base);
}
int digitalRead(uint8_t pin)
{
    uint32_t gpio_base = GPIO_BASE + pin*4;
    uint8_t tmp;
    LB(tmp, 0, gpio_base);
    return tmp & 0x1;
}