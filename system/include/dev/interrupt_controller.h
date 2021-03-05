#ifndef _INTERRUPT_CONTROLLER_H_
#define _INTERRUPT_CONTROLLER_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
void attachInterrupt(int num, void (*fun_callback)(void), int mode);
void enableInterrupt(int num);
void detachInterrupt(int num);
void enableMachineInterrupts();
void disableMachineInterrupts();
#define disableInterrupt(num) detachInterrupt(num)
#ifdef __cplusplus
}
#endif
#endif /* _INTERRUPT_CONTROLLER_H_s */