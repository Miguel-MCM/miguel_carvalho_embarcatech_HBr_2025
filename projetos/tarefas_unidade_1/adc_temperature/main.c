#include <stdio.h>
#include "pico/stdlib.h"
#include <hardware/adc.h>

#define ADC_TEMPERATURE_CHANNEL 4

void setup_adc() {
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(ADC_TEMPERATURE_CHANNEL);
}

float read_temperature() {
    uint16_t read = adc_read();
    return 27.0f - ((read*3.3f/0x1000) - 0.706f)/0.001721f;
}

int main() {
    stdio_init_all();
    setup_adc();

    while (true) {
        printf("----Temperature----\n%.03f ºC\n", read_temperature());
        sleep_ms(1000);
    }
}
