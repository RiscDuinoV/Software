#include "wiring.h"

uint64_t millis(void)
{
    uint64_t rawValue = get_mtime();
    return TICKS_TO_MS(rawValue);
}


uint64_t micros(void)
{
    uint64_t rawValue = get_mtime();
    return TICKS_TO_US(rawValue);
}