#ifndef _INTERRUPT_CONTROLLER_H_
#define _INTERRUPT_CONTROLLER_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
void attachInterrupt(uint8_t num, void (*fun_callback)(void), int mode);
void detachInterrupt(uint8_t num);
void enableMachineInterrupts();
void disableMachineInterrupts();
#ifdef __cplusplus
}
#endif
#endif /* _INTERRUPT_CONTROLLER_H_s */