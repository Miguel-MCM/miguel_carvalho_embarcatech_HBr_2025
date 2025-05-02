#include <stdio.h>
#include "pico/stdlib.h"
#include <hardware/adc.h>

#include "adc_to_celsius.h"

#define ADC_TEMPERATURE_CHANNEL 4

void setup_adc();
float read_temperature();