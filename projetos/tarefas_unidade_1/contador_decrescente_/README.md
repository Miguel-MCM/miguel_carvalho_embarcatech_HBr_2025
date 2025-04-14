# CONTADOR DECRESCENTE COM REGISTRO DE EVENTO POR INTERRUPÇÃO

## Descrição da Tarefa

Um contador de pressionamentos do botão **B** em um período de tempo a partir do pressionamento do botão **A**, com registro de eventos por meio de interrupções.

## Conteúdo

* [Descrição](#descrição)
* [Conteúdo](#conteúdo)
* [Objetivos do Projeto](#objetivos-do-projeto)
* [Lista de Materiais e Conexões](#lista-de-materiais-e-conexões)
* [Código de Configuração e Uso do Display OLED ssd1306](#código-de-configuração-e-uso-do-display-oled-ssd1306)

## Objetivos do Projeto

- Utilizar interrupção para detecção do pressionamento de botões
- Utilizar o display OLED para apresentação de informações.

## Lista de Materiais e Conexões

| Nome | Componente | Pino da Pico W | Descrição da Conexão |
|------|------------|----------------|----------------------|
| Botão A | Chave Táctil | GPIO5 | Entrada digital para confirmação e seleção (com resistor de pull-up) |
| Botão B | Chave Táctil | GPIO6 | Entrada digital para negação e retrocesso (com resistor de pull-up) |
| Display OLED | SSD1306 12C 128x64 | GP20 (SDA) e GP21 (SCL) | Comunicação I2C para o display OLED |

* Já se assume a devida conexão de Ground e VCC, para os que requerem
 alimentação, dos componentes.

 ## Código de Configuração e Uso do Display OLED ssd1306

 O código utilizado para configuração e uso do display foi um dos códigos exemplos da BitDogLab: [https://github.com/BitDogLab/BitDogLab-C/tree/main/display_oled](https://github.com/BitDogLab/BitDogLab-C/tree/main/display_oled)
