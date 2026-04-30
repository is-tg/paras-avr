#include "Arduino.h"

// F_CPU comes from platform.txt -DF_CPU={build.f_cpu}
#ifndef F_CPU
#define F_CPU 16000000L // shush clangd
#endif

void delay(unsigned long ms) {
  if (ms == 0)
    return;

  // 1. Set Timer 0 to "Classic" mode (F_SYS / 12)
  // This makes math easier for a 1ms tick.
  CKCON &= ~(1 << 3); // T0M = 0

  // 2. Set Timer 0 to Mode 1 (16-bit)
  TMOD = (TMOD & 0xF0) | 0x01;

  // 3. Calculate ticks for 1ms
  // With F_CPU at 16MHz and /12 prescaler, 1ms is ~1333
  // ticks
  uint16 ticks_per_ms = (F_CPU / 12L) / 1000L;
  uint16 reload = 65536U - (uint16)ticks_per_ms;

  TR0 = 1; // Start Timer 0

  while (ms--) {
    // Load timer registers
    TH0 = (byte)(reload >> 8);
    TL0 = (byte)(reload & 0xFF);

    // Wait for Overflow Flag (TF0)
    while (!TF0)
      ;

    TF0 = 0; // Clear flag for next loop
  }

  TR0 = 0; // Stop Timer 0 to save power
}
