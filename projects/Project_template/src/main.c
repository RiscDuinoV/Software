#include <stdio.h>
#include <dev/io.h>      // IO PERIPHERIALS
#include <dev/sio.h>     // UART
#include <riscv/mtime.h> // delay
#include <dev/i2c.h>
#ifdef __cplusplus
extern "C"
{
#endif
    int __io_putchar(int ch)
    {
        sio_putchar(IO_SIO_BYTE, (char)ch);
        return 0;
    }
#ifdef __cplusplus
}
#endif
#define EXAMPLE_BASE    0x80000000
int main(void)
{
    uint8_t data[sizeof("Hey!")];
    uint32_t Value;
    while (1)
    {
        
        printf("Hello, World\n");
        for (int i = 0; i < 8; i++)
        {
            OUTB(IO_LED, (1 << i));
            delay(100);
        }
        for (int i = 0; i < 8; i++)
        {
            OUTB(IO_LED, (0x80 >> i));
            delay(100);
        }
    }
    return 0;
}
