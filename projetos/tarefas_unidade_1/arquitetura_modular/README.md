# Monitor de Temperauta Interna da MCU

## Descrição da Tarefa

Um simples programa de blink utilizando a api cyw43_arch da Raspberry Pi Pico W.
O projeto foi feito utilizando estruturação de código com arquitetura modular.
Divindindo o código em camadas de driver, hal e app.

## Conteúdo

* [Descrição](#descrição)
* [Conteúdo](#conteúdo)
* [Objetivos do Projeto](#objetivos-do-projeto)
* [Estrutura do Projeto](#estrutura-do-projeto)
* [Código de Base](#código-de-base)

## Objetivos do Projeto

- Reestruturar um código de base para se enquadrar em uma arquitetura modular.

## Estrutura do Projeto

```
arquitetura_modular/
├── app/
│   └── main.c
├── drivers/
│   └── led_embutido.c
├── hal/
│   └── hal_led.c
├── include/
│   ├── led_embutido.h
│   └── hal_led.h
└── CMakeLists.txt
```

## Código de Base

```C
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int main() {
    stdio_init_all();
    if (cyw43_arch_init()) {
        return -1;
    }

    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(500);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(500);
    }
}
```
