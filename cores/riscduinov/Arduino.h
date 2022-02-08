#ifndef ARDUINO_H
#define ARDUINO_H

#include <sys/cdefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

__BEGIN_DECLS

#include "dev/interrupt_controller.h"
#include "wiring.h"
#include "dev/io.h"
#include "dev/gpio.h"

#define HIGH GPIO_HIGH
#define LOW GPIO_LOW

#define INPUT GPIO_INPUT
#define OUTPUT GPIO_OUTPUT
#define INPUT_PULLUP INPUT

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE  1
#define FALLING 2
#define RISING  3

// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() enable_machine_interrupts()
#define noInterrupts() disable_machine_interrupts()

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

#ifndef _NOP
#define _NOP() NOP()
#endif

typedef unsigned int word;

#define bit(b) (1UL << (b))
typedef uint8_t byte;
void pinMode(int pin, int mode);
void digitalWrite(int pin, int val);
int digitalRead(int pin);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void setup(void);
void loop(void);

__END_DECLS
// C++ Declarations
#ifdef __cplusplus
typedef bool boolean;

#include "WCharacter.h"
#include "WString.h"
#include "HardwareSerial.h"


uint16_t makeWord(uint16_t w);
uint16_t makeWord(byte h, byte l);

#define word(...) makeWord(__VA_ARGS__)

//unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);
//unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

//void tone(uint8_t _pin, unsigned int frequency, unsigned long duration = 0);
//void noTone(uint8_t _pin);

// WMath prototypes
long random(long);
long random(long, long);
void randomSeed(unsigned long);
long map(long, long, long, long, long);

#ifdef ARDUINO
static HardwareSerial Serial = HardwareSerial(UART_NUM(0));
#endif
#endif
#endif // ARDUINO_H
