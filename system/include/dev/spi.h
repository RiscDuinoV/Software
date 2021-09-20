#ifndef __SPI_H__
#define __SPI_H__
#include <sys/cdefs.h>
#include <stdint.h>
__BEGIN_DECLS
void spi_start_transfer(uint32_t base);
uint8_t spi_transfer(uint32_t base, uint8_t data);
void spi_end_transfer(uint32_t base);
void spi_set_frequecy(uint32_t base, uint32_t freq);
__END_DECLS
#endif // __SPI_H__