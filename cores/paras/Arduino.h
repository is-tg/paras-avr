#ifndef Arduino_h
#define Arduino_h

#include "N76E003.h"
#include <stdbool.h>
#include <stdint.h>

// --- Arduino Types ---
typedef uint8_t byte;
typedef uint8_t boolean;

// --- Pin Modes ---
#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2

// --- Digital Values ---
#define HIGH 1
#define LOW 0

// --- Pin Mapping ---
#define LED_BUILTIN 10 // P1.2, active-low!

// --- Function Prototypes ---
#ifdef __cplusplus
extern "C" {
#endif

void init_timers(void); // Internal setup
void setup(void);
void loop(void);

// Digital I/O
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);

// Time
void delay(unsigned long ms);
unsigned long millis(void); // Placeholder for now

#ifdef __cplusplus
}
#endif

#endif
