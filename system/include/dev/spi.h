#ifndef SPI_H_
#define SPI_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
void spi_beginTransaction(uint32_t base);
void spi_endTransaction(uint32_t base);
uint8_t spi_transfer(uint32_t base, uint8_t byte);
void spi_setClock(uint32_t base, int freq);
#ifdef __cplusplus
}
#endif
#endif // SPI_H_