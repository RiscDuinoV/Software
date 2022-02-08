#ifndef HARDWARE_SERIAL_H
#define HARDWARE_SERIAL_H
#include <stdint.h>
#include "Print.h"
class HardwareSerial : public Print
{
private:
    uint32_t m_base;
public:
    HardwareSerial(uint32_t base) {m_base = base;};
    ~HardwareSerial() {}
    void begin(uint32_t baud);
    int available();
    size_t write(char c);
    inline size_t write(uint8_t c) { return write((char)c); }
    int read();
    using Print::write; // pull in write(str) and write(buf, size) from Print
    operator bool() { return true; }
};
#endif /* HARDWARESERIAL_H_ */