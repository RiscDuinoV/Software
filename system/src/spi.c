#include "dev/spi.h"
#include "dev/io.h"
#define SPI_DATA_OFFSET     0x0
#define SPI_CMD_OFFSET      0x4
#define SPI_STATUS_OFFSET   0x4
#define SPI_BUSY            0x1
inline void spi_start_transfer(uint32_t base)
{
    SB(1, SPI_CMD_OFFSET, base);
}
int spi_transfer(uint32_t base, int data)
{
    uint32_t ret;
    SW(data, SPI_DATA_OFFSET, base);
    do
    {
        LW(ret, SPI_STATUS_OFFSET, base);
    } 
    while (ret & SPI_BUSY);
    LW(ret, SPI_DATA_OFFSET, base);
    return ret;
}
inline void spi_end_transfer(uint32_t base)
{
    SB(0, SPI_CMD_OFFSET, base);
}
void spi_set_frequency(uint32_t base, uint32_t freq)
{
    freq = ((uint64_t)freq * 2 * 65536) / F_CPU;
    SH(freq, SPI_CMD_OFFSET + 2, base); 
}
inline void spi_set_mode(uint32_t base, int mode)
{
    SB(mode, SPI_CMD_OFFSET + 1, base);
}