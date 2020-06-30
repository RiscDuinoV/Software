#include <stdint.h>
#include "dev/io.h"
#include "dev/gpio.h"
void pinMode(uint8_t pin, uint8_t mode)
{
    uint32_t gpio_base = GPIO_BASE + pin*4;
    gpio_setDirection(gpio_base, mode);
}
void digitalWrite(uint8_t pin, uint8_t val)
{
    uint32_t gpio_base = GPIO_BASE + pin*4;
    gpio_Write(gpio_base, val);
}
int digitalRead(uint8_t pin)
{
    uint32_t gpio_base = GPIO_BASE + pin*4;
    return gpio_Read(gpio_base);
}