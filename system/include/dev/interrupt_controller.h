#ifndef _INTERRUPT_CONTROLLER_H_
#define _INTERRUPT_CONTROLLER_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
void interrupt_handler();
void external_interrupt_handler();
void attach_external_interrupt(int num, void (*fun_callback)(void *), void *fun_args);
void enable_external_interrupt(int num);
void detach_external_interrupt(int num);
void timer_interrupt_handler();
void attach_timer_interrupt(int num, void (*fun_callback)(void *), void *fun_args);
void enable_timer_interrupt(int num);
void dettach_timer_interrupt(int num);
void enable_machine_interrupts();
void disable_machine_interrupts();
void enable_external_interrupts();
void disable_external_interrupts();
void enable_timer_interrupts();
void disable_timer_interrupts();
#define disableInterrupt(num) detach_external_interrupt(num)
#define attachInterrupt(num, fun_callback, mode) attach_external_interrupt(num, (void (*)(void*))fun_callback, NULL)
#ifdef __cplusplus
}
#endif
#endif /* _INTERRUPT_CONTROLLER_H_s */