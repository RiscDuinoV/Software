#ifndef FLASH_H_
#define FLASH_H_
#include <stdint.h>
uint8_t flash_read_status_register();
void flash_read(uint32_t from, uint32_t quantity, uint8_t* buf);
void flash_WR(uint32_t en);
void flash_write_byte(uint32_t address, uint8_t byte);
void flash_write_block(uint32_t from, uint32_t quantity, uint8_t* buf);
void flash_chip_erase();
#endif // FLASH_H_