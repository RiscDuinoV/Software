#ifndef GPIO_H_
#define GPIO_H_
#include <stdint.h>
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);
#endif // GPIO_H_