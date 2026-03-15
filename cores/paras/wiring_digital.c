#include "Arduino.h"
#include "N76E003.h"

void pinMode(uint8_t pin, uint8_t mode) {
  if (pin >= NUM_DIGITAL_PINS)
    return;

  uint8_t bitmask = (1 << (pin > 7 ? pin - 8 : pin));

  if (pin < 8) {
    (mode & 0b10) ? (P0M1 |= bitmask) : (P0M1 &= ~bitmask);
    (mode & 0b01) ? (P0M2 |= bitmask) : (P0M2 &= ~bitmask);
  } else {
    (mode & 0b10) ? (P1M1 |= bitmask) : (P1M1 &= ~bitmask);
    (mode & 0b01) ? (P1M2 |= bitmask) : (P1M2 &= ~bitmask);
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
