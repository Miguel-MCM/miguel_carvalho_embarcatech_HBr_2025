#include "unity.h"
#include "adc_to_celsius.h"

void setUp(void) {

}

void tearDown(void) {
}

void test_adc_to_celsius(void) {
    uint16_t adc_val_0 = 0;
    float expected_temp_0 = 437.2266124;
    TEST_ASSERT_FLOAT_WITHIN(0.01, expected_temp_0, adc_to_celsius(adc_val_0));

    uint16_t adc_val_mid = 873;
    float expected_temp_mid = 28.44306594;
    TEST_ASSERT_FLOAT_WITHIN(0.01, expected_temp_mid, adc_to_celsius(adc_val_mid));

    // Test case 3: ADC value = 4095 (maximum value)
    uint16_t adc_val_max = 4095;
    float expected_temp_max = -1480.263219;
    TEST_ASSERT_FLOAT_WITHIN(0.01, expected_temp_max, adc_to_celsius(adc_val_max));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_adc_to_celsius);
    return UNITY_END();
}


