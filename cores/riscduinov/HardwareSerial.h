#ifndef HARDWARESERIAL_H_
#define HARDWARESERIAL_H_
#include <stdint.h>
#include <Print.h>
class HardwareSerial : public Print
{
private:
    volatile uint8_t *_UART_BASE;
public:
    HardwareSerial(uint32_t base) {_UART_BASE = (volatile uint8_t *)base;}
    ~HardwareSerial() {}
    void begin(uint32_t baud);
    int available();
    size_t write(char c);
    inline size_t write(uint8_t c) { return write((char)c); }
    char read();
    using Print::write; // pull in write(str) and write(buf, size) from Print
    operator bool() { return true; }
};
#endif /* HARDWARESERIAL_H_ */