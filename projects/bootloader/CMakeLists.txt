cmake_minimum_required (VERSION 3.0)

set(BUILD_AS_BOOTLOADER TRUE)
set(ARCH "rv32i")
set(ABI "ilp32")
set(MEMSIZE "2K")
# No need to define the real value for F_CPU
set(F_CPU "12000000")
set(SECTION_START "0")
# set(BUILD_WITH_SPI "-DSPI_FLASH")
#set(CMAKE_C_FLAGS "${BUILD_WITH_SPI} -DBOOTLOADER_BUILD")
set(STACK_SIZE "0x100")
set(HEAP_SIZE "0")

set(CMAKE_TOOLCHAIN_FILE "${PROJECT_SOURCE_DIR}/../../tools/cmake/toolchain_script.cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(bootloader C ASM)
add_definitions(-DBOOTLOADER_BUILD)
# add_definitions(-DSPI_FLASH)
include("${PROJECT_SOURCE_DIR}/../../tools/cmake/options.cmake")
file(GLOB src "src/*.c")
list(FILTER crt0_src EXCLUDE REGEX interrupt_handler.S)
add_executable(${CMAKE_PROJECT_NAME} ${src} ${crt0_src})
