#include "dev/gpio.h"
#include "dev/io.h"
#define GPIO_DATA_OFFSET    0
#define GPIO_CTRL_OFFSET    4
void gpio_set_direction(uint32_t base, int direction)
{
    SB(direction, GPIO_CTRL_OFFSET, base);
}
void gpio_write(uint32_t base, int value)
{
    SW(value, GPIO_DATA_OFFSET, base);
}
int gpio_read(uint32_t base)
{
    int ret;
    LW(ret, GPIO_DATA_OFFSET, base);
    return ret;
}
void gpio_toggle(uint32_t base)
{
    int tmp;
    LW(tmp, GPIO_DATA_OFFSET, base);
    tmp = ~tmp;
    SW(tmp, GPIO_DATA_OFFSET, base);
}