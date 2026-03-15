#include "Arduino.h"

int main(void) {
  // Setup hardware timers
  init_timers();

  // Call user setup
  setup();

  // Loop forever
  while (1) {
    loop();
  }

  return 0;
}
