#ifndef _I2C_H_
#define _I2C_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "dev/io.h"
int i2c_write(uint32_t base, uint8_t address, uint8_t *ptr_buf, int len);
int i2c_read(uint32_t base, uint8_t address, uint8_t *ptr_buf, int len);
void i2c_set_frequency(uint32_t base, uint32_t freq);
void i2c_detect(uint32_t base);
#ifdef __cplusplus
}
#endif
#endif /* _I2C_H_ */
