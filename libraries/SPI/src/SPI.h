#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED
#include "Arduino.h"
#include "dev/spi.h"


#ifndef LSBFIRST
#define LSBFIRST 0
#endif
#ifndef MSBFIRST
#define MSBFIRST 1
#endif

#define SPI_CLOCK_DIV2 (F_CPU / 2)
#define SPI_CLOCK_DIV4 (F_CPU / 4)
#define SPI_CLOCK_DIV8 (F_CPU / 8)
#define SPI_CLOCK_DIV16 (F_CPU / 16)
#define SPI_CLOCK_DIV32 (F_CPU / 32)
#define SPI_CLOCK_DIV64 (F_CPU / 64)
#define SPI_CLOCK_DIV128 (F_CPU / 128)

class SPISettings
{
private:
    uint32_t m_clock;
    uint8_t m_bit_order;
    uint8_t m_mode;
    friend class SPIClass;
public:
    SPISettings(uint32_t clock, uint8_t bitOrder, uint8_t dataMode) : m_clock(clock), m_bit_order(bitOrder), m_mode(dataMode)
    {
    }
    SPISettings()
    {
        SPISettings(4000000, MSBFIRST, SPI_MODE0);
    }
};

class SPIClass
{
private:
    uint32_t m_base;
    SPISettings m_settings;
public:
    SPIClass(uint32_t base) : m_base(base) {};
    ~SPIClass() {};
    void begin();
    void usingInterrupt(uint8_t interruptNumber);
    void notUsingInterrupt(uint8_t interruptNumber);
    void beginTransaction(SPISettings settings);
    void beginTransaction();
    uint8_t transfer(uint8_t data);
    uint16_t transfer16(uint16_t data);
    void transfer(void *buf, size_t count);
    void endTransaction(void);
    void end();
    void setBitOrder(uint8_t bitOrder);
    //void attachInterrupt() {};
    //void detachInterrupt() {};
};
#ifdef ARDUINO
extern SPIClass SPI;
#endif
#endif
