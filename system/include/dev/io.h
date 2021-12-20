#ifndef _IO_H_
#define	_IO_H_
#include "riscv/io.h"


#define	IO_BASE		0xfffff800
#define	IO_ADDR(a)	(IO_BASE | (a))

#define I2C_BASE        0xFFFFF000
#define SPI_BASE        0xFFFFF200
#define GPIO_BASE       0xFFFFF600
#define UART_BASE       0xFFFFFB00

#define I2C_NUM(x)      I2C_BASE + x*4
#define SPI_NUM(x)      SPI_BASE + x*4
#define GPIO_NUM(x)     GPIO_BASE + x*8
#define UART_NUM(x)     UART_BASE + x*4

#define	IO_LED		    IO_ADDR(0x090)	/* word, WR */

#define UART0           IO_ADDR(0x300)
#define UART1           IO_ADDR(0x304)
#define UART2           IO_ADDR(0x308)
#define UART3           IO_ADDR(0x30C)
#define UART_USB_BASE   UART0

#define I2C0_BASE       IO_ADDR(0x200)

#define	IO_GPIO_DATA	IO_ADDR(0x000)	/* word, RW */
#define	IO_GPIO_CTL	IO_ADDR(0x004)	/* word, WR */
#define	IO_GPIO_RISE_IF	IO_ADDR(0x008)	/* word, RW (clear only) */
#define	IO_GPIO_RISE_IE	IO_ADDR(0x00C)	/* word, RW */
#define	IO_GPIO_FALL_IF	IO_ADDR(0x010)	/* word, RW (clear only) */
#define	IO_GPIO_FALL_IE	IO_ADDR(0x014)	/* word, RW */

//#define	IO_TIMER	IO_ADDR(0x100)	/* 16-byte, WR */

#define	IO_SIO_BYTE	IO_ADDR(0x300)	/* byte, RW */
#define	IO_SIO_STATUS	IO_ADDR(0x301)	/* byte, RD */
#define	IO_SIO_BAUD	IO_ADDR(0x302)	/* half, WR */

#define SPI_BASE0       IO_ADDR(0x340)

#define	IO_SPI_FLASH	IO_ADDR(0x340)	/* half, RW */
#define	IO_SPI_SDCARD	IO_ADDR(0x350)	/* half, RW */

#define	IO_FB		IO_ADDR(0x380)	/* word, WR */
#define	IO_TXTMODE_CTRL	IO_ADDR(0x381)	/* byte, WR */
#define	IO_C2VIDEO_BASE	IO_ADDR(0x390)	/* word, WR */

#define	IO_PCM_CUR	IO_ADDR(0x3A0)	/* word, RD */
#define	IO_PCM_FIRST	IO_ADDR(0x3A0)	/* word, WR */
#define	IO_PCM_LAST	IO_ADDR(0x3A4)	/* word, WR */
#define	IO_PCM_FREQ	IO_ADDR(0x3A8)	/* word, WR */
#define	IO_PCM_VOLUME	IO_ADDR(0x3AC)	/* half, WR */

#define	IO_LEGO_DATA	IO_ADDR(0x520)	/* byte, WR */
#define	IO_LEGO_CTL	IO_ADDR(0x521)	/* byte, WR */

#define	IO_PUSHBTN	IO_ADDR(0x700)	/* word, RD */
#define	IO_DIPSW	IO_ADDR(0x702)	/* word, RD */
#define	IO_LCD		IO_ADDR(0x712)	/* word, WR */

#define INTERRUPT_MASK      IO_ADDR(0x7E0)
#define INTERRUPT_REG       IO_ADDR(0x7E8)

#define	IO_CPU_RESET	IO_ADDR(0x7F0)	/* byte, WR */

#define IO_CPU_RESET_BOOT_TRAP  IO_ADDR(0x7FC)

/* SIO status bitmask */
#define	SIO_TX_BUSY	0x4
#define	SIO_RX_OVERRUN	0x2
#define	SIO_RX_FULL	0x1

/* Pushbutton input bitmask */
#define	ROT_A		0x40
#define	ROT_B		0x20
#define	BTN_CENTER	0x10
#define	BTN_UP		0x08
#define	BTN_DOWN	0x04
#define	BTN_LEFT	0x02
#define	BTN_RIGHT	0x01

/* PMOD output mask */
#define	PMOD_J1_MASK	0x0f
#define	PMOD_J2_MASK	0xf0

/* LCD control output bitmask */
#define	LCD_DATA	0x0f
#define	LCD_RS		0x10
#define	LCD_E		0x20

#define MTIME_BASE          0xFFFFF400
#define MTIMECMP_BASE       MTIME_BASE + 8

#endif /* !_IO_H_ */
