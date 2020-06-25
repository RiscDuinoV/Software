#include <dev/io.h>
#include <dev/sio.h>
uint8_t sio_available(uint32_t base)
{
    uint8_t c;
    //INB(c, x);
	LB(c, 1, base);
    return (c & SIO_RX_FULL);
}
uint8_t sio_getch(uint32_t base)
{
    uint8_t c;
    //INB(c, base);
	while (!sio_available(base));
	LB(c, 0, base);
	return c;
}

int sio_putchar(uint32_t base, const uint8_t c)
{
	uint8_t s;
	do
	{
		//INB(s, base + 1);
		LB(s, 1, base);
	} 
	while (s & SIO_TX_BUSY);
	//OUTB(IO_SIO_BYTE, (c));
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
int sio_printNumber(uint32_t base, unsigned long n, uint8_t base_print)
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
int sio_printFloat(uint32_t base, double number, uint8_t digits)
{
    int n = 0;
	uint64_t *tmp = ((uint64_t *)&number);
	
    if (*tmp == 0x7FFFFFFFFFFFFFFF || *tmp == 0x7FF8000000000001 || *tmp == 0x7FF0000000000001) return sio_puts(base, "nan");
    if (*tmp == 0x7FF0000000000000 || *tmp == 0xFFF0000000000000) return sio_puts(base, "inf");
    if (number > 4294967040.0) return sio_puts(base, "ovf");  // constant determined empirically
    if (number < -4294967040.0) return sio_puts(base, "ovf");  // constant determined empirically

    // Handle negative numbers
    if (number < 0.0)
    {
        n += sio_putchar(base, '-');
        number = -number;
    }

    // Round correctly so that print(1.999, 2) prints as "2.00"
    double rounding = 0.5;
    for (uint8_t i = 0; i < digits; ++i)
        rounding /= 10.0;

    number += rounding;

    // Extract the integer part of the number and print it
    unsigned long int_part = (unsigned long)number;
    double remainder = number - (double)int_part;
    n += sio_printNumber(base, int_part, 10);

    // Print the decimal point, but only if there are digits beyond
    if (digits > 0) {
        n += sio_putchar(base, '.');
    }

    // Extract digits from the remainder one at a time
    while (digits-- > 0)
    {
        remainder *= 10.0;
        unsigned int toPrint = (unsigned int)(remainder);
        n += sio_printNumber(base, toPrint, 10);
        remainder -= toPrint;
    }
    return n;
}
