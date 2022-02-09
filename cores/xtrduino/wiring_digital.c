#include "dev/gpio.h"
void pinMode(int pin, int mode)
{
    gpio_set_direction(GPIO_NUM(pin), mode);
}
void digitalWrite(int pin, int val)
{
    gpio_write(GPIO_NUM(pin), val);
}
int digitalRead(int pin)
{
    return gpio_read(GPIO_NUM(pin));
}