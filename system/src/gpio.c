#include "dev/gpio.h"
#include "dev/io.h"
void gpio_setDirection(uint32_t base, uint8_t direction)
{
    uint8_t tmp;
    LB(tmp, 2, base);
    tmp = (tmp & 0x6) | (direction & 0x1);
    SB(tmp, 2, base);
}
void gpio_Write(uint32_t base, uint32_t value)
{
    SH(value, 0, base);
}
int gpio_Read(uint32_t base)
{
    uint8_t tmp;
    LH(tmp, 0, base);
    return tmp;
}
void gpio_Toggle(uint32_t base)
{
    uint16_t tmp;
    LH(tmp, 0, base);
    tmp = ~tmp;
    SH(tmp, 0, base);
}