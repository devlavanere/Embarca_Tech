cmake_minimum_required(VERSION 3.13)
project(fila_queue C CXX ASM)

# Caminho completo do SDK já instalado
set(PICO_SDK_PATH "C:/Users/fborg/.pico-sdk/sdk/2.1.1")

# Inicializa o SDK
include(${PICO_SDK_PATH}/pico_sdk_init.cmake)
pico_sdk_init()

# Cria o executável
add_executable(fila_queue
    main.c
)

# Vincula as bibliotecas necessárias (inclui suporte a multicore)
target_link_libraries(fila_queue
    pico_stdlib
    pico_multicore
)

# Gera UF2, bin, hex...
pico_add_extra_outputs(fila_queue)
