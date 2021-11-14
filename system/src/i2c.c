#include "dev/i2c.h"
#include "dev/io.h"

#define I2C_EN          0x100
#define I2C_TRG         0x200
#define I2C_WRITE       0x400
#define I2C_BUSY        0x200
#define I2C_ACK         0x100
#define I2C_LAST        0x800
#define I2C_STOP(base)  SH(0, 0, base)
static int s_i2c_write(uint32_t base, int data)
{
    int ret;
    SH(data | I2C_EN | I2C_TRG | I2C_WRITE, 0, base);
    do
    {
        LW(data, 0, base);
    } while (data & I2C_BUSY);
    if (data & I2C_ACK)
        ret = -1;
    else
        ret = 0;
    return ret;
}
static int s_i2c_read(uint32_t base, uint8_t *data, int isLast)
{
    int ret;
    do
    {
        LW(ret, 0, base);
    } while (ret & I2C_BUSY);
    SH(I2C_EN | I2C_TRG | (isLast ? I2C_LAST : 0), 0, base);
    do
    {
        LW(ret, 0, base);
    } while (ret & I2C_BUSY);
    *data = ret;
    return 0;
}

int i2c_write(uint32_t base, uint8_t address, uint8_t *ptr_buf, int len)
{
    int ret;
    do
    {
        LW(ret, 0, base);
    } while (ret & I2C_BUSY);
    ret = 0;
    if (!s_i2c_write(base, address))
    {
        for (int i = 0; i < len; i++)
        {
            if (s_i2c_write(base, ptr_buf[i]))
            {
                ret = -2;
                break;
            }
        }
    }
    else
    {
        ret = -1;
    }
    I2C_STOP(base);
    return ret;    
}
int i2c_read(uint32_t base, uint8_t address, uint8_t *ptr_buf, int len)
{
    int ret;
    do
    {
        LW(ret, 0, base);
    } while (ret & I2C_BUSY);
    ret = 0;
    if (!s_i2c_write(base, address))
    {
        for (int i = 0; i < len; i++)
        {
            s_i2c_read(base, &ptr_buf[i], i == len - 1);
        }
    }
    else
    {
        ret = -1;
    }
    I2C_STOP(base);
    return ret;
}