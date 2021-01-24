cmake_minimum_required (VERSION 3.0)

set(ARCH "rv32i")
set(ABI "ilp32")
set(MEMSIZE "20K")
set(F_CPU "100000000")
set(SECTION_START "2K")

set(CMAKE_TOOLCHAIN_FILE "${PROJECT_SOURCE_DIR}/../../tools/cmake/Toolchain_Script.cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(ProjectTemplate C ASM)
include("${PROJECT_SOURCE_DIR}/../../tools/cmake/Options.cmake")
include_directories(inc)    # Include header files .h
add_subdirectory(lib)       # Compile static libraries
add_subdirectory(src)       # Source code
