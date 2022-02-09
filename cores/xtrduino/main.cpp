#define ARDUINO_MAIN
#include "Arduino.h"
void init()
{
    enable_machine_interrupts();
    enable_external_interrupts();
}

int main(void)
{
    init();
    setup();
    for (;;)
    {
        loop();
    }
}