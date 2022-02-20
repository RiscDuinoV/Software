#ifndef HARDWARE_SERIAL_H
#define HARDWARE_SERIAL_H
#include <stdint.h>
#include "Stream.h"
class HardwareSerial : public Stream
{
private:
    uint32_t m_base;
public:
    HardwareSerial(uint32_t base) {m_base = base;};
    ~HardwareSerial() {}
    void begin(uint32_t baud);
    int available();
    size_t write(uint8_t c);
    int peek();
    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    int read();
    using Print::write; // pull in write(str) and write(buf, size) from Print
    operator bool() { return true; }
};
#ifdef ARDUINO
extern HardwareSerial Serial;
#endif
#endif /* HARDWARESERIAL_H_ */