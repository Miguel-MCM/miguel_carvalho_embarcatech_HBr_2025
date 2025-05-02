#include "hal_led.h"

int main() {
    while (1) {
        if (hal_led_toogle()) {
            return -1; // Error initializing the LED
        }
        sleep_ms(500);
    }
}