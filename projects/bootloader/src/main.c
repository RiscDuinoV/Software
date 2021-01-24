#include <stdint.h>
#include "dev/io.h"
#include "dev/sio.h"
#define HEADER_WORD 0xCAFECAFE
#ifdef SPI_FLASH
#include "flash.h"
#endif
const char* ARCH = "RISC-V\n\r";
typedef enum status_t {GET_HEADER = 0, GET_ADR, GET_SIZE, GET_DATA} status_t;
void sio_pchar(uint8_t c)
{
    int s;
    do
    {
        INB(s, IO_SIO_STATUS);
    } while (s & SIO_TX_BUSY);
    OUTB(IO_SIO_BYTE, (c));
}
void boot(void* pc)
{
    __asm __volatile__(
    "mv ra, zero;"
        "jr %0;"
        :
    : "r" (pc)
        );
}
int main()
{
    uint8_t byte;
    uint32_t word;
    int gotWord = 0;
    status_t bootloader_status = GET_HEADER;
    uint32_t begin_addr = 0;
    uint32_t size = -1;
    uint32_t *mem_ptr = (void *)0;
#ifdef SPI_FLASH
    uint8_t ram_only = 0;
#endif // SPI_FLASH
    LW(word, 0, IO_CPU_RESET_BOOT_TRAP);
    if (!(word & 0x3))
    {
        if ((word & ~0x3) != 0)
            boot((void *)word);
#ifdef SPI_FLASH
        flash_read(0, 4, (uint8_t*)&word);
        if (word == 0xC0DEF32C)
        {
            flash_read(4, 4, (uint8_t*)&word);
            mem_ptr = (uint32_t *)word;
            flash_read(8, 4, (uint8_t*)&word);
            flash_read(12, word, (uint8_t *)mem_ptr);
            boot((void*)mem_ptr);
        }
#endif /* SPI_FLASH */
    }
#ifdef SPI_FLASH
    else
        ram_only = (word & 0x2) ? 1 : 0;
#endif // SPI_FLASH
    for (byte = 0; ARCH[byte] != '\0'; byte++)
    {
        sio_pchar(ARCH[byte]);
    }
    while (1)
    {
        do
        {
            LB(byte, 1, UART_USB_BASE);
        }
        while (!(byte & SIO_RX_FULL));
        LB(byte, 0, UART_USB_BASE);
        ((uint8_t *)(&word))[gotWord] = byte;
        gotWord = (gotWord + 1) % 4;
        if (!(gotWord % 4))
        {
            switch (bootloader_status)
            {
            case GET_HEADER:
                if (word == HEADER_WORD)
                    bootloader_status = GET_ADR;
                break;
            case GET_ADR:
                begin_addr = word;
                mem_ptr = (uint32_t *)word;
                bootloader_status = GET_SIZE;
                break;
            case GET_SIZE:
                size = word / 4;
                bootloader_status = GET_DATA;
                break;
            default:
                *mem_ptr = word;
                mem_ptr++;
                size--;
                break;
            }
            if (!size)
            {
#ifdef SPI_FLASH
                if (!ram_only)
                {
                    flash_chip_erase();
                    word = 0xC0DEF32C;
                    flash_write_block(0, 4, (uint8_t*)&word);
                    flash_write_block(4, 4, (uint8_t*)&begin_addr);
                    word = (uint32_t)mem_ptr;
                    flash_write_block(8, 4, (uint8_t*)&word);
                    word = (uint32_t)mem_ptr - word;
                    mem_ptr = (uint32_t *)begin_addr;
                    flash_write_block(12, word, (uint8_t *)mem_ptr);
                }
#endif /* SPI_FLASH */
                SW(begin_addr, 0, IO_CPU_RESET_BOOT_TRAP);
            }
        }
    }
    return 0;
}
