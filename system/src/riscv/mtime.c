#include <riscv/mtime.h>
#include <dev/io.h>
#ifndef F_CPU
#error "You must define CPU frequency as a macro!"
#endif
#define MS		(uint32_t)(1e-3 * F_CPU)
#define US      (uint32_t)(1e-6 * F_CPU)
volatile uint64_t *mtime_reg    = (volatile uint64_t *)MTIME_BASE;
volatile uint64_t *mtimecmp_reg = (volatile uint64_t *)MTIMECMP_BASE;
inline uint64_t get_mtime()
{
	return *mtime_reg;
}
inline void set_mtime_cmp(uint64_t val)
{
	*mtimecmp_reg = val;
}
inline uint64_t get_mtime_cmp()
{
	return *mtimecmp_reg;
}
void delay_ms(uint32_t ms)
{
	uint64_t endval = MS * ms + get_mtime_cmp();
	while (get_mtime() < endval);
}
void delay_us(uint32_t us)
{
	uint64_t endval = US * us + get_mtime_cmp();
	while (get_mtime() < endval);
}