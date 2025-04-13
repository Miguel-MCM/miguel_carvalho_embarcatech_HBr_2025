#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <string.h>

#include "ssd1306.h"

// ssd1306 display definitions
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define I2C_FREQ (400*1000)
#define I2C_ADDR ssd1306_i2c_port

uint8_t ssd[ssd1306_buffer_length];
struct render_area frame_area;

// buttons definitions
#define A_BUTTOM_PIN 5
#define B_BUTTOM_PIN 6

uint8_t time_counter = 0;
uint16_t press_counter = 0;
bool counting = false;

absolute_time_t next_sec_time;

void gpio_irq_buttom(uint gpio, uint32_t events) {
    switch (gpio) {
    case A_BUTTOM_PIN:
        if (!counting) {
            counting = true;
            time_counter = 9;
            press_counter = 0;
            next_sec_time = make_timeout_time_ms(1000);
        }
        break;
    case B_BUTTOM_PIN:
        if (counting) {
            press_counter++;
        }
    default:
        break;
    }
}

void setup_ssd1306();
void setup_buttom(uint pin);

int main() {
    stdio_init_all();
    
    setup_ssd1306();
    setup_buttom(A_BUTTOM_PIN);
    setup_buttom(B_BUTTOM_PIN);

    while (true) {
        if (counting) {
            if (get_absolute_time() > next_sec_time) {
                if (--time_counter == 0) {
                    counting = false;
                }
                next_sec_time = make_timeout_time_ms(1000);
            }
        }
        
        ssd1306_draw_uint16(ssd, 15, ssd1306_height/2-4, time_counter, 1);
        ssd1306_draw_uint16(ssd, ssd1306_width-15-24, ssd1306_height/2-4, press_counter, 3);

        render_on_display(ssd, &frame_area);
    }
}

void setup_ssd1306() {
    i2c_init(I2C_PORT, I2C_FREQ);

    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init();

    frame_area.start_column = 0;
    frame_area.end_column = ssd1306_width-1;
    frame_area.start_page = 0;
    frame_area.end_page = ssd1306_n_pages-1;

    calculate_render_area_buffer_length(&frame_area);
    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);

}

void setup_buttom(uint pin) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_up(pin);

    gpio_set_irq_enabled_with_callback(pin, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_buttom);
}
