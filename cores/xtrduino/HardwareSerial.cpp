#include "HardwareSerial.h"
#include "dev/sio.h"
#include "dev/io.h"
void HardwareSerial::begin(uint32_t baud)
{
    sio_set_baud(m_base, baud);
}
int HardwareSerial::available()
{
    return sio_available(m_base);
}
size_t HardwareSerial::write(uint8_t c)
{
    sio_putchar(m_base, c);
    return 1;
}
int HardwareSerial::read()
{
    int c;
    c = sio_getch(m_base);
    return c;
}
int HardwareSerial::peek()
{
    return -1;
}

#ifdef ARDUINO
HardwareSerial Serial = HardwareSerial(UART_NUM(0));
#endif