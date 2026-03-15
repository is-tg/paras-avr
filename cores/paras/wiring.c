#include "Arduino.h"

// 16Mhz clock
#define CLOCK 16000000L
// Divide by 12
#define T0CLOCK ((CLOCK) / 12L)
// Per milisecond
#define T0_1MS ((T0CLOCK) / 1000L)

void delay(unsigned long ms) {
  uint16_t reload = (uint16_t)(65536UL - T0_1MS);

  // 1. Configure Timer 0 Clock Input
  // N76E003 Datasheet: CKCON Register (Page 90)
  // Bit 3 (T0M) defines the clock source for Timer 0.
  // 0 = System clock divided by 12 (We want this)
  // 1 = System clock divided by 1
  // Since we want value 0 at bit 3, we clear just that bit.
  CKCON &= ~(1 << 3);

  // 2. Configure Timer 0 Mode
  // TMOD Register: Bits 0 and 1 control Timer 0 Mode.
  // We want Mode 1 (16-bit timer), which is binary 01.
  // We must clear bit 1 and set bit 0.
  // This preserves Timer 1 settings (bits 4-7).
  TMOD = (TMOD & ~0x03) | 0x01;

  // Start Timer
  TR0 = 1;

  while (ms != 0) {
    // Load the 16-bit reload value
    TL0 = reload & 0xFF;
    TH0 = reload >> 8;

    // Wait for overflow
    while (!TF0)
      ;
    TF0 = 0;

    ms--;
  }
  TR0 = 0;
}
