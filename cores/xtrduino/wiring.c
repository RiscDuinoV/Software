#include "wiring.h"

uint64_t millis(void)
{
    uint64_t rawValue = get_mtime();
    return rawValue * 1000 / F_CPU;
}


uint64_t micros(void)
{
    uint64_t rawValue = get_mtime();
    return rawValue * 1000000 / F_CPU;
}