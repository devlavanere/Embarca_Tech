# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Generated CMake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

# Define a placa
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Importa o SDK do Pico
include(pico_sdk_import.cmake)

project(mutex_spinlock_rp2040 C CXX ASM)

# Inicializa o SDK
pico_sdk_init()

# Cria o executável com o main.c
add_executable(mutex_spinlock_rp2040 main.c)

# Nome e versão do programa
pico_set_program_name(mutex_spinlock_rp2040 "mutex_spinlock_rp2040")
pico_set_program_version(mutex_spinlock_rp2040 "0.1")

# Ativa apenas saída USB
pico_enable_stdio_uart(mutex_spinlock_rp2040 0)
pico_enable_stdio_usb(mutex_spinlock_rp2040 1)

# Bibliotecas necessárias
target_link_libraries(mutex_spinlock_rp2040
    pico_stdlib
    hardware_sync
)

# Diretórios de include
target_include_directories(mutex_spinlock_rp2040 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Gera UF2, bin, etc.
pico_add_extra_outputs(mutex_spinlock_rp2040)
