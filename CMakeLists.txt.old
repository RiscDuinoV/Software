cmake_minimum_required(VERSION 3.0)
#Set processor architecture (MIPS, RISC-V)
set(LIBRARY_BUILD TRUE)
set(F_CPU "12000000")

# Specifiy where is the .cmake script is.
set(CMAKE_TOOLCHAIN_FILE "${PROJECT_SOURCE_DIR}/../../Tools/Compiler/Toolchain_Script.cmake")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/system/lib/riscv)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/system/lib/riscv)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/system/bin)

project(RISC-V ASM C CXX)

include_directories(cores/riscduinov)
include_directories(system/include)
add_subdirectory(cores/riscduinov)
add_subdirectory(system/src)
