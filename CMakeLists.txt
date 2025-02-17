# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(main C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(main main.c 
                src/ani_01.c 
                src/teclado.c 
                src/buzzer.c 
                src/ani_asterisco.c 
                src/ani_04.c 
                src/leds.c 
                src/ani_02.c 
                src/ani_05.c 
                src/ani_06.c
                src/ani_07.c
                src/ani_03.c
                src/ani_tecla_b.c
                src/ani_tecla_c.c 
                src/bot_d.c
                src/tecla_hashtag.c)

pico_set_program_name(main "main")
pico_set_program_version(main "0.1")

# Generate PIO header
pico_generate_pio_header(main ${CMAKE_CURRENT_LIST_DIR}/ws2818b.pio)

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(main 0)
pico_enable_stdio_usb(main 1)

# Add the standard library to the build
target_link_libraries(main
        hardware_pio
        hardware_pwm
        hardware_clocks
        pico_cyw43_arch_none # Adiciona suporte ao CYW43 sem multitarefa
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(main PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(main 
        
        )

pico_add_extra_outputs(main)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)