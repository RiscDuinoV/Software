#define ARDUINO_MAIN
#include "Arduino.h"
#include "SrcWrapper.h"
void init()
{
    enableMachineInterrupts();
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