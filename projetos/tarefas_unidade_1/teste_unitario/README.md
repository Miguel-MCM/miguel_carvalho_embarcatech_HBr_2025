# Testes Unitários

## Descrição da Tarefa

Foi feita uma função para converter a leitura do ADC interno de temperatura da Pico W para graus celsius.

Em seguida foi feito um teste unitário, utilizando a biblioteca [Unity](https://github.com/ThrowTheSwitch/Unity), para esta função, garantindo o seu funcionamento para entradas e saídas conhecidas.


## Conteúdo

* [Descrição](#descrição)
* [Conteúdo](#conteúdo)
* [Objetivos do Projeto](#objetivos-do-projeto)
* [Compilando os Testes](#compilando-os-testes)

## Objetivos do Projeto

- Aplicar o conceito de testes unitários no âmbito de programação para microcontroladores.

## Compilando os Testes
Para compilar os testes é necessário adicionar a biblioteca `unity` à pasta `tests`, para isso basta copiar a pasta `src` do repositório da biblioteca e mudar seu nome para `unity`.

```bash
git clone https://github.com/ThrowTheSwitch/Unity.git
cp -r src caminho/para/esse/repositorio/tests/unity
```

Em seguida basta acessar a pasta `tests` e executar o script `compile.bat` se estiver no sistema operacional Windows ou `compile.sh` se estiver no Linux.

```bash
cd tests
./compile.bat
```

O executável dos testes se chamará `test_adc_to_celsius.exe` ou `test_adc_to_celsius`. 
