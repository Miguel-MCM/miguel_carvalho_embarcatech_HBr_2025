#include "main.h"

void setup_adc() {
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(ADC_TEMPERATURE_CHANNEL);
}

float read_temperature() {
    uint16_t read = adc_read();
    printf("ADC Value: %d\n", read);
    return adc_to_celsius(read);
}

int main()
{
    stdio_init_all();
    setup_adc();

    while (true) {
        printf("----Temperature----\n%.0f ºC\n", read_temperature());
        sleep_ms(1000);
    }
}
