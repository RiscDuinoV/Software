#include <dev/interrupt_controller.h>
#include <dev/io.h>
#include <dev/sio.h>
#include <riscv/csr.h>
volatile uint64_t *intr_mask = (volatile uint64_t *)INTERRUPT_MASK;
volatile uint64_t *intr_reg = (volatile uint64_t *)INTERRUPT_REG;  
void (*fun_ptr)(void); 
uint32_t intr_vect[64] = {0};
void interrupt_handler()
{
    uint64_t mask;
    int i;
    for (i = 0; i < 64; i++)
    {
        mask = (1ULL << i);
        if ((*intr_reg & *intr_mask & mask) == mask)
        {
            fun_ptr = (void *)intr_vect[i];
            (*fun_ptr)();
        }
    }
}
void attachInterrupt(uint8_t num, void (*fun_callback)(void))
{
    if (num < 64)
    {
        intr_vect[num] = (uint32_t)fun_callback;
        *intr_mask |= (uint64_t)(1ULL << num);
    }
}
void detachInterrupt(uint8_t num)
{
    if (num < 64)
    {
        *intr_mask &= ~(uint64_t)(1ULL << num);
    }
}
void enableMachineInterrupts()
{
    csr_read_set(mie, 0x800);
    csr_read_set(mstatus, MSTATUS_MIE);
}
void disableMachineInterrupts()
{
    csr_read_clear(mstatus, MSTATUS_MIE);
    csr_read_clear(mie, 0x800);
}