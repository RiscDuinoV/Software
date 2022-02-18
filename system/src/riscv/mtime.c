#include "riscv/mtime.h"
#include "dev/io.h"
static volatile uint64_t *s_mtime_reg    = (volatile uint64_t *)MTIME_BASE;
static volatile uint64_t *s_mtimecmp_reg = (volatile uint64_t *)MTIMECMP_BASE;
inline uint64_t get_mtime()
{
	return *s_mtime_reg;
}
inline void set_mtime_cmp(uint64_t val)
{
	*s_mtimecmp_reg = val;
}
inline uint64_t get_mtime_cmp()
{
	return *s_mtimecmp_reg;
}
void delay_ms(uint32_t ms)
{
	uint64_t endval = MS_TO_TICKS(ms) + get_mtime();
	//uint64_t endval = MS * ms + get_mtime();
	while (get_mtime() < endval);
}
void delay_us(uint32_t us)
{
	uint64_t endval = US_TO_TICKS(us) + get_mtime();
	//uint64_t endval = US * us + get_mtime();
	while (get_mtime() < endval);
}