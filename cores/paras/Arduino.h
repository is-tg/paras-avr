#ifndef Arduino_h
#define Arduino_h

#include "N76E003.h"

typedef unsigned char byte;
typedef unsigned short uint16;

enum { LOW, HIGH };

// 0 0 Quasi-bidirectional
// 0 1 Push-pull
// 1 0 Input-only (high-impedance)
// 1 1 Open-drain
enum {
  INPUT_PULLUP,
  OUTPUT,
  INPUT,
  OPEN_DRAIN,
};

#define NUM_DIGITAL_PINS 16 // +2 ?

void setup(void);
void loop(void);

void pinMode(byte pin, byte mode);
void digitalWrite(byte pin, byte val);
int digitalRead(byte pin);

void delay(unsigned long ms);

#endif
