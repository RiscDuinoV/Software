cmake_minimum_required (VERSION 3.0)

set(F_CPU "100000000")
set(SECTION_START "2K")
set(MEMSIZE "32K")
set(STACK_SIZE "0x500")
set(HEAP_SIZE "0x1000")
set(ApplicationName "Sortie")
# set(SERIAL_PORT "/dev/ttyS20")

set(CMAKE_TOOLCHAIN_FILE "${PROJECT_SOURCE_DIR}/../../tools/cmake/Toolchain_Script.cmake")


set(CMAKE_ASM_FLAGS "-DportasmHANDLE_INTERRUPT=interrupt_handler -DTRAP_ENTRY=freertos_risc_v_trap_handler")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
project(FreeRTOS_template C ASM)
include_directories(inc)
include_directories(FreeRTOSKernel/include)
include_directories(FreeRTOSKernel/portable/GCC/RISC-V)
include_directories(FreeRTOSKernel/portable/GCC/RISC-V/chip_specific_extensions/RV32I_CLINT_no_extensions)
# add_subdirectory(FreeRTOSKernel)
# add_subdirectory(lib) # Go in that folder and read the CMakeLists.txt
include("${PROJECT_SOURCE_DIR}/../../tools/cmake/Options.cmake")
add_subdirectory(src)
