#include "dev/interrupt_controller.h"
#include "dev/io.h"
#include "dev/sio.h"
#include "riscv/csr.h"
volatile uint64_t *external_interrupt_mask = (volatile uint64_t *)INTERRUPT_MASK;
volatile uint64_t *external_interrupt_register = (volatile uint64_t *)INTERRUPT_REG;
void (*fun_ptr)(void);
static uint32_t external_interrupt_vector[64] = {0};
static uint32_t timer_interrupt_vector = 0;
void interrupt_handler()
{
    switch (csr_read(mcause) & 0x7FFFFFFFU)
    {
    case MCAUSE_MACHINE_EXTERNAL:
        external_interrupt_handler();
        break;
    case MCAUSE_MACHINE_TIMER:
        timer_interrupt_handler();
        break;
    default:
        break;
    }
}
void external_interrupt_handler()
{
    uint64_t mask;
    int i;
    for (i = 0; i < 64; i++)
    {
        mask = (1ULL << i);
        if ((*external_interrupt_register & *external_interrupt_mask & mask) == mask)
        {
            fun_ptr = (void *)external_interrupt_vector[i];
            (*fun_ptr)();
        }
    }
}
void attach_external_interrupt(int num, void (*fun_callback)(void))
{
    if (num < 64 && num >= 0)
    {
        external_interrupt_vector[num] = (uint32_t)fun_callback;
        *external_interrupt_mask |= (uint64_t)(1ULL << num);
    }
}
void enable_external_interrupt(int num)
{
    if (num < 64 && num >= 0)
        *external_interrupt_mask |= (uint64_t)(1ULL << num);
}
void detach_external_interrupt(int num)
{
    if (num < 64)
        *external_interrupt_mask &= ~((uint64_t)(1ULL << num));
}
void timer_interrupt_handler()
{
    fun_ptr = (void *)(timer_interrupt_vector);
    (*fun_ptr)();
}
void attach_timer_interrupt(int num, void (*fun_callback)(void))
{
    if (!num)
    {
        timer_interrupt_vector = (uint32_t)fun_callback;
    }
}
void enable_timer_interrupt(int num)
{

}
void dettach_timer_interrupt(int num)
{

}
inline void enable_machine_interrupts()
{
    csr_read_set(mstatus, MSTATUS_MIE);
}
inline void disable_machine_interrupts()
{
    csr_read_clear(mstatus, MSTATUS_MIE);
}
inline void enable_external_interrupts()
{
    csr_read_set(mie, MIE_MEIE);
}
inline void disable_external_interrupts()
{
    csr_read_clear(mie, MIE_MEIE);
}
inline void enable_timer_interrupts()
{
    csr_read_set(mie, MIE_MTIE);
}
inline void disable_timer_interrupts()
{
    csr_read_clear(mie, MIE_MTIE);
}