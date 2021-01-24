#include "flash.h"
#include "dev/io.h"
#include "dev/spi.h"
uint8_t flash_read_status_register()
{
    uint32_t c;
    spi_start_transaction(IO_SPI_FLASH);
    spi_byte(IO_SPI_FLASH, 0x05);
    c = spi_byte(IO_SPI_FLASH, 0xFF);
    spi_end_transaction(IO_SPI_FLASH);
    return (c & 0xFF);
}
void flash_read(uint32_t from, uint32_t quantity, uint8_t* buf)
{
    int i;
    spi_start_transaction(IO_SPI_FLASH);
    spi_byte(IO_SPI_FLASH, 0x03);
    i = 24;
    do
    {
        i -= 8;
        spi_byte(IO_SPI_FLASH, (from >> i) & 0xFF);
    } 
    while (i != 0);
    for (i = 0; i < quantity; ++i)
    {
        buf[i] = spi_byte(IO_SPI_FLASH, 0xFF);
    }
    spi_end_transaction(IO_SPI_FLASH);
}
void flash_WR(uint32_t en)
{
    spi_start_transaction(IO_SPI_FLASH);
    if (en)
    {
        spi_byte(IO_SPI_FLASH, 0x06);
    }
    else
    {
        spi_byte(IO_SPI_FLASH, 0x04);
    }
    spi_end_transaction(IO_SPI_FLASH);
}
void flash_write_byte(uint32_t address, uint8_t byte)
{
    int i;
    flash_WR(1);
    spi_start_transaction(IO_SPI_FLASH);
    spi_byte(IO_SPI_FLASH, 0x02);
    i = 24;
    do
    {
        i -= 8;
        spi_byte(IO_SPI_FLASH, (address >> i));
    } 
    while (i != 0);
    spi_byte(IO_SPI_FLASH, byte);
    spi_end_transaction(IO_SPI_FLASH);
    flash_WR(0);
}
void flash_write_block(uint32_t from, uint32_t quantity, uint8_t* buf)
{
    for (int i = 0; i < quantity; ++i)
    {
        while (flash_read_status_register() & 0x01);
        flash_write_byte(from + i, buf[i]);
    }
}
void flash_chip_erase()
{
    flash_WR(1);
    spi_start_transaction(IO_SPI_FLASH);
    spi_byte(IO_SPI_FLASH, 0x60);
    spi_end_transaction(IO_SPI_FLASH);
    flash_WR(0);
}