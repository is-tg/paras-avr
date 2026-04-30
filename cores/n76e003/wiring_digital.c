#include "Arduino.h"

void pinMode(byte pin, byte mode) {
  byte bitmask = (1 << (pin & 7));

  // Port 0
  if (pin < 8) {
    (mode & 0b10) ? (P0M1 |= bitmask) : (P0M1 &= ~bitmask);
    (mode & 0b01) ? (P0M2 |= bitmask) : (P0M2 &= ~bitmask);
  }
  // Port 1
  else {
    (mode & 0b10) ? (P1M1 |= bitmask) : (P1M1 &= ~bitmask);
    (mode & 0b01) ? (P1M2 |= bitmask) : (P1M2 &= ~bitmask);
  }
}

void digitalWrite(byte pin, byte val) {
  byte bitmask = (1 << (pin & 7));

  // Port 0
  if (pin < 8) {
    if (val)
      P0 |= bitmask;
    else
      P0 &= ~bitmask;
  }
  // Port 1
  else {
    if (val)
      P1 |= bitmask;
    else
      P1 &= ~bitmask;
  }
}

int digitalRead(byte pin) {
  byte bitmask = (1 << (pin & 7));

  // Port 0
  if (pin < 8) {
    return (P0 & bitmask) ? HIGH : LOW;
  }
  // Port 1
  else {
    return (P1 & bitmask) ? HIGH : LOW;
  }
  return LOW;
}
