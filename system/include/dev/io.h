#ifndef _IO_H_
#define	_IO_H_
#include "riscv/io.h"

#define I2C_BASE        0xFFFFF000
#define SPI_BASE        0xFFFFF200
#define GPIO_BASE       0xFFFFF600
#define UART_BASE       0xFFFFFB00

#define I2C_NUM(x)      (I2C_BASE + (x)*64)
#define SPI_NUM(x)      (SPI_BASE + (x)*64)
#define GPIO_NUM(x)     (GPIO_BASE + (x)*8)
#define UART_NUM(x)     (UART_BASE + (x)*64)

#define UART_USB_BASE   UART_NUM(0)


#define MTIME_BASE          0xFFFFF400
#define MTIMECMP_BASE       (MTIME_BASE + 8)

#define INTERRUPT_CONTROLLER_BASE 0xFFFFFC00

#define BOOT_TRAP_BASE 0xFFFFFFFC

#endif /* !_IO_H_ */
