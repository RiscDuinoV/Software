#ifndef _I2C_H_
#define _I2C_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <dev/io.h>
int i2c_write(uint32_t base, uint8_t address, const uint8_t *buffer, int len);
int i2c_read(uint32_t base, uint8_t address, uint8_t *buffer, int len);
#ifdef __cplusplus
}
#endif
#endif /* _I2C_H_ */