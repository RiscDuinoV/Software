#ifndef _INTERRUPT_CONTROLLER_H_
#define _INTERRUPT_CONTROLLER_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
void interrupt_handler();
void externalInterruptHandler();
void attachExternalInterrupt(int num, void (*fun_callback)(void));
void enableExternalInterrupt(int num);
void detachExternalInterrupt(int num);
void timerInterruptHandler();
void attachTimerInterrupt(int num, void (*fun_callback)(void));
void enableTimerInterrupt(int num);
void dettachTimerInterrupt(int num);
void enableMachineInterrupts();
void disableMachineInterrupts();
void enableExternalInterrupts();
void disableExternalInterrupts();
void enableTimerInterrupts();
void disableTimerInterrupts();
#define disableInterrupt(num) detachInterrupt(num)
#define attachInterrupt(num, fun_callback, mode) attachExternalInterrupt(num, fun_callback)
#ifdef __cplusplus
}
#endif
#endif /* _INTERRUPT_CONTROLLER_H_s */