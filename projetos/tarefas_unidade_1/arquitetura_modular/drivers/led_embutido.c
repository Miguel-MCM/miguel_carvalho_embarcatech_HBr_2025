#include "led_embutido.h"

int setup_led_embutido() {
    stdio_init_all();
    if (cyw43_arch_init()) {
        return -1;
    }
    return 0;
}

void led_embutido(bool state) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, state);
}