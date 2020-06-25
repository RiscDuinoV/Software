#include <HardwareSerial.h>
#include <dev/io.h>
void HardwareSerial::begin(uint32_t baud)
{
    uint32_t val;

    val = baud;
    if (baud > 1000000)
    val /= 10;
    val = val * 1024 / 1000 * 1024 / (F_CPU / 1000) + 1;
    if (baud > 1000000)
    val *= 10;

    volatile uint16_t  *hp = (volatile uint16_t *)&_UART_BASE[2];
    *hp = val;
}
int HardwareSerial::available()
{
    return _UART_BASE[1] & SIO_RX_FULL;
}
size_t HardwareSerial::write(char c)
{
    while (_UART_BASE[1] & SIO_TX_BUSY);
    _UART_BASE[0] = c;
    return 1;
}
char HardwareSerial::read()
{
    return _UART_BASE[0];
}