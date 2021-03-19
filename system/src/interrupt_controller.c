#include <dev/interrupt_controller.h>
#include <dev/io.h>
#include <dev/sio.h>
#include <riscv/csr.h>
volatile uint64_t *extIntrMask = (volatile uint64_t *)INTERRUPT_MASK;
volatile uint64_t *extIntrReg = (volatile uint64_t *)INTERRUPT_REG;
void (*fun_ptr)(void);
static uint32_t extIntrVect[64] = {0};
static uint32_t timerIntrVect = 0;
void interrupt_handler()
{
    switch (csr_read(mcause) & 0x7FFFFFFFU)
    {
    case MCAUSE_MACHINE_EXTERNAL:
        externalInterruptHandler();
        break;
    case MCAUSE_MACHINE_TIMER:
        timerInterruptHandler();
        break;
    default:
        break;
    }
}
void externalInterruptHandler()
{
    uint64_t mask;
    int i;
    for (i = 0; i < 64; i++)
    {
        mask = (1ULL << i);
        if ((*extIntrReg & *extIntrMask & mask) == mask)
        {
            fun_ptr = (void *)extIntrVect[i];
            (*fun_ptr)();
        }
    }
}
void attachExternalInterrupt(int num, void (*fun_callback)(void))
{
    if (num < 64 && num >= 0)
    {
        extIntrVect[num] = (uint32_t)fun_callback;
        *extIntrMask |= (uint64_t)(1ULL << num);
    }
}
void enableExternalInterrupt(int num)
{
    if (num < 64 && num >= 0)
        *extIntrMask |= (uint64_t)(1ULL << num);
}
void detachExternalInterrupt(int num)
{
    if (num < 64)
        *extIntrMask &= ~((uint64_t)(1ULL << num));
}
void timerInterruptHandler()
{
    fun_ptr = (void *)(timerIntrVect);
    (*fun_ptr)();
}
void attachTimerInterrupt(int num, void (*fun_callback)(void))
{
    if (!num)
    {
        timerIntrVect = (uint32_t)fun_callback;
    }
}
void enableTimerInterrupt(int num)
{

}
void dettachTimerInterrupt(int num)
{

}
inline void enableMachineInterrupts()
{
    csr_read_set(mstatus, MSTATUS_MIE);
}
inline void disableMachineInterrupts()
{
    csr_read_clear(mstatus, MSTATUS_MIE);
}
inline void enableExternalInterrupts()
{
    csr_read_set(mie, MIE_MEIE);
}
inline void disableExternalInterrupts()
{
    csr_read_clear(mie, MIE_MEIE);
}
inline void enableTimerInterrupts()
{
    csr_read_set(mie, MIE_MTIE);
}
inline void disableTimerInterrupts()
{
    csr_read_clear(mie, MIE_MTIE);
}