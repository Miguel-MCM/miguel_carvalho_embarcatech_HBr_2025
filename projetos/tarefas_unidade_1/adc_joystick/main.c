#include <stdio.h>
#include "pico/stdlib.h"
#include <hardware/adc.h>

#define ANALOGIC_X_PIN 27
#define ANALOGIC_Y_PIN 26
#define ADC_GPIO_INPUT(pin) ((pin)-26)

void setup_joystick() {
    adc_init();
    adc_gpio_init(ANALOGIC_X_PIN);
    adc_gpio_init(ANALOGIC_Y_PIN);
}

float read_joystick(int pin) {
    uint16_t read;
    adc_select_input(ADC_GPIO_INPUT(pin));
    read = adc_read();

    return ((float)(read - 0x7ff))/0x7ff;
}

int main() {
    stdio_init_all();

    setup_joystick();

    while (true) {
        printf("----Leitura----\n");
        printf("X: %.02f\nY: %.02f\n", read_joystick(ANALOGIC_X_PIN), read_joystick(ANALOGIC_Y_PIN));
        sleep_ms(1000);
    }
}
