#include "dev/io.h"
#include "dev/sio.h"
#include <stdarg.h>
#define	SIO_TX_BUSY	0x4
#define	SIO_RX_FULL	0x1
int sio_available(uint32_t base)
{
    int c;
	LB(c, 1, base);
    return (c & SIO_RX_FULL);
}
int sio_getch(uint32_t base)
{
    int c;
	while (!sio_available(base));
	LB(c, 0, base);
	return c;
}

int sio_putchar(uint32_t base, int c)
{
	int s;
	do
	{
		LB(s, 1, base);
	} 
	while (s & SIO_TX_BUSY);
	SB(c, 0, base);
	return 1;
}
int sio_puts(uint32_t base, const char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		sio_putchar(base, str[i]);
		if (str[i] == '\n')
			sio_putchar(base, '\r');
		i++;
	}
	return i;
}
int sio_print_number(uint32_t base, uint32_t n, int base_print)
{
    char buf[8 * sizeof(long) + 1]; // Assumes 8-bit chars plus zero byte.
    char* str = &buf[sizeof(buf) - 1];
    *str = '\0';

    // prevent crash if called with base_print == 1
    if (base_print < 2) base_print = 10;

    do {
        char c = n % base_print;
        n /= base_print;

        *--str = c < 10 ? c + '0' : c + 'A' - 10;
    } while (n);

    return sio_puts(base, str);
}
int sio_print_float(uint32_t base, float number, int digits)
{
    int n = 0;
    uint32_t *number32 = (uint32_t *)&number;
    if (((*number32) & 0x7F800000) == 0x7F800000)
    {
        if (((*number32) & 0x007FFFFF) != 0)
            sio_puts(base, "nan\n");
        else if ((*number32) & 0x80000000)
            sio_puts(base, "-inf\n");
        else
            sio_puts(base, "inf\n");
    }
    // Handle negative numbers
    if (number < 0.0f)
    {
        n += sio_putchar(base, '-');
        number = -number;
    }

    // Round correctly so that print(1.999, 2) prints as "2.00"
    double rounding = 0.5;
    for (int i = 0; i < digits; ++i)
        rounding /= 10.0;

    number += rounding;

    // Extract the integer part of the number and print it
    unsigned long int_part = (unsigned long)number;
    float remainder = number - (float)int_part;
    n += sio_print_number(base, int_part, 10);

    // Print the decimal point, but only if there are digits beyond
    if (digits > 0) 
        n += sio_putchar(base, '.');

    // Extract digits from the remainder one at a time
    while (digits-- > 0)
    {
        remainder *= 10.0f;
        unsigned int toPrint = (unsigned int)(remainder);
        n += sio_print_number(base, toPrint, 10);
        remainder -= toPrint;
    }
    return n;
}
int sio_print_double(uint32_t base, double number, int digits)
{
    int n = 0;
	uint64_t *tmp = ((uint64_t *)&number);
	
    if (*tmp == 0x7FFFFFFFFFFFFFFF || *tmp == 0x7FF8000000000001 || *tmp == 0x7FF0000000000001) return sio_puts(base, "nan");
    if (*tmp == 0x7FF0000000000000 || *tmp == 0xFFF0000000000000) return sio_puts(base, "\n\r");
    if (number > 4294967040.0) return sio_puts(base, "ovf\n\r");  // constant determined empirically
    if (number < -4294967040.0) return sio_puts(base, "ovf\n\r");  // constant determined empirically

    // Handle negative numbers
    if (number < 0.0)
    {
        n += sio_putchar(base, '-');
        number = -number;
    }

    // Round correctly so that print(1.999, 2) prints as "2.00"
    double rounding = 0.5;
    for (int i = 0; i < digits; ++i)
        rounding /= 10.0;

    number += rounding;

    // Extract the integer part of the number and print it
    unsigned long int_part = (unsigned long)number;
    double remainder = number - (double)int_part;
    n += sio_print_number(base, int_part, 10);

    // Print the decimal point, but only if there are digits beyond
    if (digits > 0) {
        n += sio_putchar(base, '.');
    }

    // Extract digits from the remainder one at a time
    while (digits-- > 0)
    {
        remainder *= 10.0;
        unsigned int toPrint = (unsigned int)(remainder);
        n += sio_print_number(base, toPrint, 10);
        remainder -= toPrint;
    }
    return n;
}
char *sio_gets(uint32_t base, char *str)
{
    int c;
    while ((c = sio_getch(base)) != '\n')
    {
        *str = c;
        str++;
    }
    return str;
}
int sio_printf(uint32_t base, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int c;
    int ret = 0;
    while ((c = *format++) != 0)
    {
        ret++;
        if ((c == '%') && ((c = *format++) != 0))
        {
            ret++;
            if (c == 'c')
            {
                int v = va_arg(args, int);
                sio_putchar(base, v);
            }
            else if (c == 'd')
            {
                int v = va_arg(args, int);
                sio_print_number(base, v, 10);
            }
            else if (c == 'x')
            {
                uint32_t v = va_arg(args, uint32_t);
                sio_print_number(base, v, 16);
            }
            else if (c == 's')
            {
                const char *str = va_arg(args, const char *);
                sio_puts(base, str);
            }
            #ifdef SIO_PRINTF_FLOAT
            else if (c == 'f')
            {
                double f = va_arg(args, double);
                sio_print_float(base, f, 16);
            }
            #endif
            else
            {
                ret--;
            }
        }
        else 
        {
            sio_putchar(base, c);
        }
    }
    va_end(args);
    return ret;
}
#define X 262144
#define Y 64
void sio_set_baud(uint32_t base, uint32_t baud)
{
    int baud_value = (baud * Y)/(uint32_t)((F_CPU / X) + 0.5);
    //sio_puts(base, "baud_value = ");
    //sio_print_number(base, baud_value, 10);
    //sio_puts(base, "\n\r");
    SW(baud_value, 4, base);
}
__attribute__((weak)) int __io_putchar(int ch)
{
    return sio_putchar(UART_NUM(0), ch);
}
__attribute__((weak)) int __io_getchar()
{    
    return sio_getch(UART_NUM(0));
}