#ifndef __SPI_H__
#define __SPI_H__
#include <sys/cdefs.h>
#include <stdint.h>
__BEGIN_DECLS
#define SPI_MODE0 0
#define SPI_MODE1 1
#define SPI_MODE2 2
#define SPI_MODE3 3
#define SPI_MSB_FIRST 0
#define SPI_LSB_FIRST 4
#define SPI_SLAVE_SELECT_NORMAL 0
#define SPI_SLAVE_SELECT_INVERTED 1
void spi_start_transfer(uint32_t base);
int spi_transfer(uint32_t base, int data);
void spi_end_transfer(uint32_t base);
void spi_set_frequency(uint32_t base, uint32_t freq);
void spi_set_settings(uint32_t base, uint8_t mode, uint8_t bit_order);
void spi_set_slave_select_polarity(uint32_t base, uint8_t polarity);
__END_DECLS
#endif // __SPI_H__