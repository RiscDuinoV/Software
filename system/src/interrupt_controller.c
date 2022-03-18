#include "dev/interrupt_controller.h"
#include "dev/io.h"
#include "riscv/csr.h"
#include <stdio.h>
#define INTERRUPT_SRC_OFFSET 0
#define INTERRUPT_MASK_OFFSET 8
#define INTERRUPT_CONTROL_OFFSET 0
#define INTERRUPT_NUM_OFFSET (4*4)
volatile uint64_t *external_interrupt_src = (volatile uint64_t *)(INTERRUPT_CONTROLLER_BASE + INTERRUPT_SRC_OFFSET);
volatile uint64_t *external_interrupt_mask = (volatile uint64_t *)(INTERRUPT_CONTROLLER_BASE + INTERRUPT_MASK_OFFSET);
void (*fun_ptr)(void *args);
static uint32_t external_interrupt_vector[64] = {0};
static uint32_t external_interrupt_args[64] = {0};
static uint32_t timer_interrupt_vector = 0;
void interrupt_handler()
{
    switch (csr_read(mcause) & 0x7FFFFFFFU)
    {
    case MCAUSE_MACHINE_EXTERNAL:
        external_interrupt_handler();
        SW(0, 0, INTERRUPT_CONTROLLER_BASE); // Dummy write to finish isr fsm in vhdl
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
/*
    uint64_t mask, masked_interrupt;
    int i;
    masked_interrupt = *external_interrupt_src & *external_interrupt_mask;
    mask = 1;
    for (i = 0; i < 64; i++)
    {
        if ((masked_interrupt & mask) == mask)
        {
            fun_ptr = (void *)external_interrupt_vector[i];
            (*fun_ptr)();
        }
        mask = (mask << 1);
    }
*/
    int interrupt_num;
    LW(interrupt_num, INTERRUPT_NUM_OFFSET, INTERRUPT_CONTROLLER_BASE);
    fun_ptr = (void *)external_interrupt_vector[interrupt_num];
    (*fun_ptr)((void *)external_interrupt_args[interrupt_num]);
}
void attach_external_interrupt(int num, void (*fun_callback)(void *), void *fun_args)
{
    if (num < 64 && num >= 0)
    {
        external_interrupt_vector[num] = (uint32_t)fun_callback;
        external_interrupt_args[num] = (uint32_t)fun_args;
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
    (*fun_ptr)(NULL);
}
void attach_timer_interrupt(int num, void (*fun_callback)(void *), void *fun_args)
{
    //if (!num)
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