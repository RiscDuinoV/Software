cmake_minimum_required (VERSION 3.0)

set(F_CPU "100e6")
set(SECTION_START "2K")
set(MEMSIZE "32K")
set(STACK_SIZE "0x500")
set(HEAP_SIZE "0x1000")
set(ARCH "rv32i")
set(ABI "ilp32")

set(CMAKE_TOOLCHAIN_FILE "${PROJECT_SOURCE_DIR}/../../tools/cmake/toolchain_script.cmake")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
project(freertos_template.elf C ASM)
include_directories(inc)

include("${PROJECT_SOURCE_DIR}/../../tools/cmake/options.cmake")

include_directories(inc)

file(GLOB src src/*.c)
add_executable(${CMAKE_PROJECT_NAME} ${src} ${crt0_src} ${xtr_soc_src} ${arduino_src})  

include(FreeRTOSKernel/CMakeLists.txt)

# Important
target_link_libraries(${CMAKE_PROJECT_NAME} c)
target_link_libraries(${CMAKE_PROJECT_NAME} gcc)