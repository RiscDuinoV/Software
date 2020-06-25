#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <dev/io.h>


#define PWM_BASE    IO_ADDR(0x400)

void pwm_duty_write(uint32_t PWM_BASE_ADDR, uint16_t duty);
void pwm_freq_write(uint32_t PWM_BASE_ADDR, uint16_t freq);
void pwm_config_write(uint32_t PWM_BASE_ADDR, uint8_t rst, uint8_t en);
#ifdef __cplusplus
}
#endif