#include <stdio.h>
#include "dev/io.h"      // IO PERIPHERIALS
#include "dev/sio.h"     // UART
#include "riscv/mtime.h" // delay
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
int main(void)
{
    while (1)
    {
        printf("Hello, World\n");
        delay(1000);
    }
    return 0;
}
