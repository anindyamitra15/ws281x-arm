cmake_minimum_required(VERSION 3.12)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# project name and languages
project(cpp-sdk C CXX ASM)

# C/Cpp standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# game starts
pico_sdk_init()

# file(s) to compile
add_executable(${PROJECT_NAME}
    main.c
)

# compiler generates .hex, .bin and .uf2 files
pico_add_extra_outputs(${PROJECT_NAME})

# linker scripts for libraries used in project
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
)

#UART and USB setting
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)