# Tarefas - Unidade 1

## Descrição

Neste projeto se encontram todas as atividades feitas com objetivo de estudo da unidade 1 do curso de residência em sistemas embarcados da Embarcatech.


## Conteúdo

* [Descrição](#descrição)
* [Conteúdo](#conteúdo)
* [Lista de Tarefas](#lista-de-tarefas)
* [Como Começar](#como-começar)
    * [Pré-requisitos](#pré-requisitos)
    * [Construindo o Projeto](#construindo-o-projeto)
    * [Realizando o Flash para a Pico](#realizando-o-flash-para-a-pico)
* [Licença](#licença)

## Lista de Tarefas

| Tarefa | Descrição | Conteúdo Trabalhado |
|--------|-----------|---------------------|
| [Contador Decrescente com Registro de Eventos por Interrupção](contador_decrescente_) | Um contador de pressionamentos do botão **B** em um período de tempo a partir do pressionamento do botão **A**, com registro de eventos por meio de interrupções. | Uso de interrupções de GPIO para registro de eventos |
| [Leitura dos Sinais Analógicos do Joystick](adc_joystick) | Lê as entradas analógicas do joystick e, após fazer a conversão, exibe os valores lidos pela interface USB. | Leitura de sinais analógicos por meio de conversores analógico digital |
| [Monitor de Temperauta Interna da MCU](adc_temperature) | Lê a entrada analógica do sensor interno de temperatura da RP2040 e, após fazer a conversão, exibe o valor lido pela interface USB. | Leitura de sinais analógicos por meio de conversores analógico digital & Uso do sensor interno de temperatura da RP2040 |

## Como Começar

Siga estas instruções para configurar o ambiente de desenvolvimento e executar o projeto no seu Raspberry Pi Pico.

### Pré-requisitos

Certifique-se de que tem as seguintes ferramentas instaladas:

* **SDK do Raspberry Pi Pico:** O ambiente de desenvolvimento para o RP2040. Consulte o [Guia de Início Rápido do Raspberry Pi Pico](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html#getting-started) para obter instruções de instalação.
* **CMake:** Uma ferramenta de construção cross-platform.
* **Um compilador ARM GCC:** Necessário para compilar o código para o RP2040. Geralmente incluído com a SDK do Pico.
* **Python 3:** Necessário para algumas ferramentas da SDK do Pico.
* **picotool:** Uma ferramenta para interagir com o Pico (incluída na SDK).

### Construindo o Projeto

1.  Clone este repositório para a sua máquina local:
    ```bash
    git clone https://github.com/Miguel-MCM/miguel_carvalho_embarcatech_HBr_2025
    cd miguel_carvalho_embarcatech_HBr_2025/projetos/tarefas_unidade_1/<Tarefa que deseje construir>
    ```

2.  Crie um diretório de build:
    ```bash
    mkdir build
    cd build
    ```

3.  Configure o build utilizando o CMake, certificando-se de que a variável `PICO_SDK_PATH` esteja corretamente definida para o local da sua instalação da SDK do Pico:
    ```bash
    export PICO_SDK_PATH="/caminho/para/a/sua/pico-sdk" # Substitua pelo seu caminho real
    cmake ..
    ```
    Se estiver a usar o Windows, poderá precisar de usar uma sintaxe diferente para definir a variável de ambiente.

4.  Compile o projeto:
    ```bash
    make -j4
    ```

   Isto irá gerar os ficheiros binários necessários, incluindo o ficheiro `.uf2` que será usado para realizer o flash para a Pico.

### Realizando o Flash para a Pico

1.  Certifique-se de que o seu Raspberry Pi Pico não está ligado ao computador.
2.  Mantenha o botão `BOOTSEL` no seu Pico pressionado enquanto o conecta ao seu computador via USB. Isto irá montar o Pico como um disco removível chamado `RPI-RP2`.
3.  Copie o ficheiro `.uf2` encontrado no diretório `build` (normalmente com o nome do projeto, ex: `BitDogCalendar.uf2`) para o disco `RPI-RP2`.
4.  O Pico irá reiniciar automaticamente e começar a executar o código.


## Licença

[GPL-3.0 license](LICENSE)
