# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)
# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(tests C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(teste_unitario main.c adc_to_celsius.c)

pico_set_program_name(teste_unitario "teste_unitario")
pico_set_program_version(teste_unitario "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(teste_unitario 0)
pico_enable_stdio_usb(teste_unitario 1)

# Add the standard library to the build
target_link_libraries(teste_unitario
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(teste_unitario PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(teste_unitario 
        hardware_adc
        )

pico_add_extra_outputs(teste_unitario)

