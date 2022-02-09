cmake_minimum_required (VERSION 3.0)

set(ARCH "rv32i")
set(ABI "ilp32")
set(MEMSIZE "20K")
set(F_CPU "100e6")
set(SECTION_START "2K")
set(STACK_SIZE "2K")
set(HEAP_SIZE "2K")

set(CMAKE_TOOLCHAIN_FILE "${PROJECT_SOURCE_DIR}/../../tools/cmake/Toolchain_Script.cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(project_template.elf C ASM)
include("${PROJECT_SOURCE_DIR}/../../tools/cmake/Options.cmake")
file(GLOB src "src/*.c")

add_executable(${CMAKE_PROJECT_NAME} ${src} ${crt0_src} ${xtr_soc_src} ${arduino_src})

# Important
target_link_libraries(${CMAKE_PROJECT_NAME} c)
target_link_libraries(${CMAKE_PROJECT_NAME} gcc)