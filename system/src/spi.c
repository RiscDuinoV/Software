#include "dev/spi.h"
#include "dev/io.h"
inline void spi_beginTransaction(uint32_t base)
{
    SB(1, 1, base);
}
inline void spi_endTransaction(uint32_t base)
{
    SB(0, 1, base);
}
uint8_t spi_transfer(uint32_t base, uint8_t byte)
{
    uint32_t ret;
    SB(byte, 0, base);
    NOP();
    do
    {
    	LW(ret, 0, base);
    } 
    while (ret & 0x100);
    return ret;
}
void spi_setClock(uint32_t base, int freq)
{
    uint32_t val = freq *  131072 / F_CPU;
    LH(val, 2, base);
}