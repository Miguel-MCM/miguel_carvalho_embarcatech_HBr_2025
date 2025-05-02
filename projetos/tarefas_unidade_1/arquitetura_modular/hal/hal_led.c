#include "hal_led.h"

int hal_led_toogle() {
    static bool setup_done = false;
    static bool led_state = false;

    if (!setup_done) {
        if (setup_led_embutido())
            return -1;
        setup_done = true;
    }

    led_state = !led_state;
    led_embutido(led_state);
    return 0;
}