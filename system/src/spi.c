#include "dev/spi.h"
#include "dev/io.h"
#define SPI_BUSY    0x100
inline void spi_start_transfer(uint32_t base)
{
    SB(1, 1, base);
}
uint8_t spi_transfer(uint32_t base, uint8_t data)
{
    uint32_t ret;
    SB(data, 0, base);
    do
    {
        LW(ret, 0, base);
    } 
    while (ret & SPI_BUSY);
    return ret;
}
inline void spi_end_transfer(uint32_t base)
{
    SB(0, 1, base);
}
void spi_set_frequecy(uint32_t base, uint32_t freq)
{
    SH((freq * 65536) / F_CPU, 1, base); 
}