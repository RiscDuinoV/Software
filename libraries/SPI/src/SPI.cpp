#include "SPI.h"
#include "dev/io.h"
#include "dev/spi.h"
void SPIClass::begin()
{

}
void SPIClass::usingInterrupt(uint8_t interruptNumber)
{

}
void SPIClass::notUsingInterrupt(uint8_t interruptNumber)
{

}
void SPIClass::beginTransaction(SPISettings settings)
{
    m_settings = settings;
    spi_set_frequency(m_base, m_settings.m_clock);
    spi_set_settings(m_base, m_settings.m_mode, (m_settings.m_bit_order & 0x1) << 2);
    beginTransaction();
}
void SPIClass::beginTransaction()
{
    spi_start_transfer(m_base);
}
uint8_t SPIClass::transfer(uint8_t data)
{
    return spi_transfer(m_base, data);
}
uint16_t SPIClass::transfer16(uint16_t data)
{
    int ret;
    ret = transfer(data);
    ret = (ret << 8) | transfer(data >> 8);
    return ret;
}
void SPIClass::transfer(void *buf, size_t count)
{
    const uint8_t *ptr_byte = (const uint8_t *)buf;
    for (size_t i = 0; i < count; i++)
        spi_transfer(m_base, ptr_byte[i]);
}
void SPIClass::endTransaction(void)
{
    spi_end_transfer(m_base);
}
void SPIClass::end()
{
    spi_end_transfer(m_base);
}
void SPIClass::setBitOrder(uint8_t bitOrder)
{
    m_settings.m_bit_order = bitOrder;
    spi_set_settings(m_base, m_settings.m_mode, (m_settings.m_bit_order & 0x1) << 2);
}
#ifdef ARDUINO
SPIClass SPI(SPI_NUM(0));
#endif