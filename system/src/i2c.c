#include <dev/i2c.h>
static void s_i2c_waitTransmission(uint32_t base)
{
    int busy;
    do
    {
        LB(busy, 1, base);
    } 
    while (busy & 0x1);
}
static int s_i2c_write(uint32_t base, uint8_t byte)
{
    uint16_t tmp;
    s_i2c_waitTransmission(base);
    tmp = 0xA00 | byte;
    SH(tmp, 0, base);
    s_i2c_waitTransmission(base);
    LB(tmp, 1, base);
    return (tmp >> 1) & 0x1;
}
static int s_i2c_read(uint32_t base, uint8_t *byte)
{
    uint16_t tmp;
    s_i2c_waitTransmission(base);
    SH(0x900, 0, base);       // Start Read
    s_i2c_waitTransmission(base);
    LH(tmp, 0, base);
    *byte = tmp & 0xFF;
    return (tmp >> 9) & 0x1;   
}
int i2c_write(uint32_t base, uint8_t address, const uint8_t *buffer, int len)
{
    address = address << 1;
    if (s_i2c_write(base, address))
    {
        uint16_t tmp;
        do
        {
            LB(tmp, 1, base);
        } 
        while ((tmp & 0x1) != 0);   // Check if busy
        SH(0x400, 0, base);
        return -1;
    }
    for (int i = 0; i < len; i++)
    {
        if (s_i2c_write(base, buffer[i]))
            break;
    }
    SH(0x400, 0, base);
    return 0;
}
int i2c_read(uint32_t base, uint8_t address, uint8_t *buffer, int len)
{
    address = address << 1 | 1;
    if (s_i2c_write(base, address))
    {
        uint16_t tmp;
        do
        {
            LB(tmp, 1, base);
        } 
        while ((tmp & 0x1) != 0);   // Check if busy
        SH(0x400, 0, base);
        return -1;
    }
    for (int i = 0; i < len; i++)
    {
        if (s_i2c_read(base, &buffer[i]))
            break;
    }
    SH(0x400, 0, base);
    return 0;
}