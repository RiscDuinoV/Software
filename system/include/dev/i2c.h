#ifndef _I2C_H_
#define _I2C_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <dev/io.h>
int i2cWrite(uint32_t base, uint8_t address, uint8_t *ptr_buffer, uint32_t len);
int i2cRead(uint32_t base, uint8_t address, uint8_t *ptr_buffer, uint32_t len);
#ifdef __cplusplus
}
#endif
#endif /* _I2C_H_ */