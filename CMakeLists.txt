cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)

#-------------------------------------------------------------------------------
# User configuration
#-------------------------------------------------------------------------------
# Project name
set(PROJECT_NAME    ArduinoLibraryMemoryUsage)

# Library directory
set(LIBRARY_DIR     C:/Users/Erwin/Documents/Arduino/libraries)

# Configure board, default Arduino UNO
set(BOARD           uno)

# Configure sketch
set(SKETCH examples/PrintMemoryUsage/PrintMemoryUsage.ino)

# Configure serial port, such as:
#     Windows: COM1
#     Linux:   /dev/ttyUSB0
set(SERIAL_PORT     COM16)

#-------------------------------------------------------------------------------
# Project configuation
#-------------------------------------------------------------------------------
# Configure project
project(${PROJECT_NAME})

set(MEMORY_USAGE_LIBRARY_DIR    ${LIBRARY_DIR}/ArduinoLibraryMemoryUsage/src)

include_directories(${MEMORY_USAGE_LIBRARY_DIR})

generate_arduino_library(
        MemoryUsageLib
        SRCS
            ${MEMORY_USAGE_LIBRARY_DIR}/MemoryUsage.cpp
        HDRS
            ${MEMORY_USAGE_LIBRARY_DIR}/MemoryUsage.h
)

set(${CMAKE_PROJECT_NAME}_SKETCH    ${SKETCH})
set(${CMAKE_PROJECT_NAME}_LIBS      MemoryUsageLib)
set(${CMAKE_PROJECT_NAME}_BOARD     ${BOARD})
set(${CMAKE_PROJECT_NAME}_PORT      ${SERIAL_PORT})

generate_arduino_firmware(${CMAKE_PROJECT_NAME})
