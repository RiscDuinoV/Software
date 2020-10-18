#include <dev/i2c.h>
#define START_TRANSMISSION  0x8
#define END_TRANSMISSION    0x4
#define TRIG_WRITE          0x2
#define TRIG_READ           0x1
#define ACK_FLAG            0x4
#define BUSY_FLAG           0x1
static uint8_t s_isBusy(uint32_t base)
{
    uint8_t busy;
    LB(busy, 1, base);
    return busy & BUSY_FLAG;
}
static void s_StartTranmission(uint32_t base)
{
    SB(START_TRANSMISSION, 1, base);
}
static void s_EndTransmission(uint32_t base)
{
    SB(END_TRANSMISSION, 1, base);
}
static uint8_t s_getAck(uint32_t base)
{
    uint8_t ack;
    LB(ack, 1, base);
    return ack & ACK_FLAG;
}
static uint8_t s_i2cWrite(uint32_t base, uint8_t data)
{
    SB(data, 0, base);
    SB(TRIG_WRITE, 1, base);
    NOP();
    while (s_isBusy(base));
    return s_getAck(base);
}
static void s_i2cRead(uint32_t base, uint8_t *data)
{
    SB(TRIG_READ, 1, base);
    NOP();
    while (s_isBusy(base));
    LB(*data, 0, base);
}
int i2cWrite(uint32_t base, uint8_t address, uint8_t *ptr_buffer, uint32_t len)
{
    s_StartTranmission(base);
    address <<= 1;
    while (s_isBusy(base));
    if (s_i2cWrite(base, address))
        return -1;
    for (uint32_t i = 0; i < len; i++)
        if (s_i2cWrite(base, ptr_buffer[i]))
            return -1;
    s_EndTransmission(base);
    return 0;
}
int i2cRead(uint32_t base, uint8_t address, uint8_t *ptr_buffer, uint32_t len)
{
    s_StartTranmission(base);
    address = (address << 1) | 1;
    while (s_isBusy(base));
    if (s_i2cWrite(base, address))
        return -1;
    for (uint32_t i = 0; i < len; i++)
        s_i2cRead(base, &ptr_buffer[i]);
    s_EndTransmission(base);
    return 0;
}
