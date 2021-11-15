#ifndef __SPI_H__
#define __SPI_H__
#include <sys/cdefs.h>
#include <stdint.h>
__BEGIN_DECLS
void spi_start_transfer(uint32_t base);
int spi_transfer(uint32_t base, int data);
void spi_end_transfer(uint32_t base);
void spi_set_frequency(uint32_t base, uint32_t freq);
void spi_set_mode(uint32_t base, int mode);
__END_DECLS
#endif // __SPI_H__