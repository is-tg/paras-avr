#include "Arduino.h"

// Timer reload value for 1ms at 16MHz (Sysclk/12)
#define TIMER_RELOAD_VALUE (65536 - 1334)

// Call this once from main()
void init_timers(void) {
  CKCON &= ~0x08; // Timer 0 uses System Clock / 12
  TMOD &= 0xF0;   // Clear Timer 0 bits
  TMOD |= 0x01;   // Set Timer 0 to Mode 1 (16-bit)

  TR0 = 0; // Stop timer initially
  TF0 = 0; // Clear overflow flag
}

// Your optimized delay implementation
void delay(unsigned long ms) {
  while (ms != 0) {
    // Reload the timer for 1ms tick
    TH0 = TIMER_RELOAD_VALUE >> 8;
    TL0 = TIMER_RELOAD_VALUE & 0xFF;

    TF0 = 0; // Clear overflow flag
    TR0 = 1; // Start Timer 0

    // Wait for overflow
    while (TF0 != 1)
      ;

    TR0 = 0; // Stop Timer 0
    ms--;
  }
}

// TODO: Implement millis() using a timer interrupt
unsigned long millis(void) { return 0; }
