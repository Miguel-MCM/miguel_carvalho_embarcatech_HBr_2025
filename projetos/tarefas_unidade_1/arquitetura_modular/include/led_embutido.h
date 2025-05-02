#ifndef LED_EMBUTIDO_H
#define LED_EMBUTIDO_H

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int setup_led_embutido();

void led_embutido(bool state);

#endif // LED_EMBUTIDO_H