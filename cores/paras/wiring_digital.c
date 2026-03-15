#include "Arduino.h"

void pinMode(uint8_t pin, uint8_t mode) {
  // --- Handle Port 0 (Pins 0-7) ---
  if (pin < 8) {
    uint8_t bitmask = (1 << pin);

    if (mode == OUTPUT) {
      // Push-Pull: M1=0, M2=1
      P0M1 &= ~bitmask;
      P0M2 |= bitmask;
    } else if (mode == INPUT) {
      // Input (High-Impedance): M1=1, M2=0
      P0M1 |= bitmask;
      P0M2 &= ~bitmask;
    } else { // INPUT_PULLUP (Quasi-Bidirectional)
      // Quasi: M1=0, M2=0
      P0M1 &= ~bitmask;
      P0M2 &= ~bitmask;
      // Optionally write 1 to enable the weak pull-up
      P0 |= bitmask;
    }
  }
  // --- Handle Port 1 (Pins 8-15) ---
  else if (pin >= 8 && pin <= 15) {
    uint8_t bitmask = (1 << (pin - 8)); // Shift by 0-7

    if (mode == OUTPUT) {
      P1M1 &= ~bitmask;
      P1M2 |= bitmask;
    } else if (mode == INPUT) {
      P1M1 |= bitmask;
      P1M2 &= ~bitmask;
    } else { // INPUT_PULLUP
      P1M1 &= ~bitmask;
      P1M2 &= ~bitmask;
      P1 |= bitmask;
    }
  }
}

void digitalWrite(uint8_t pin, uint8_t val) {
  // Port 0
  if (pin < 8) {
    if (val)
      P0 |= (1 << pin);
    else
      P0 &= ~(1 << pin);
  }
  // Port 1
  else if (pin >= 8 && pin <= 15) {
    uint8_t bitmask = (1 << (pin - 8));
    if (val)
      P1 |= bitmask;
    else
      P1 &= ~bitmask;
  }
}

int digitalRead(uint8_t pin) {
  // Port 0
  if (pin < 8) {
    return (P0 & (1 << pin)) ? HIGH : LOW;
  }
  // Port 1
  else if (pin >= 8 && pin <= 15) {
    uint8_t bitmask = (1 << (pin - 8));
    return (P1 & bitmask) ? HIGH : LOW;
  }
  return LOW;
}
