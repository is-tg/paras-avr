#ifndef Arduino_h
#define Arduino_h

#include "N76E003.h"
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t byte;
typedef uint8_t boolean;

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

// TODO: move to pins_arduino.h
#define NUM_DIGITAL_PINS 16

#ifdef __cplusplus
extern "C" {
#endif

void init_timers(void);
void setup(void);
void loop(void);

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);

void delay(unsigned long ms);
#ifdef __cplusplus
}
#endif

#endif
