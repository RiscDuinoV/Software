# Specify the program tool
set(PROGRAM_TOOL "${CMAKE_CURRENT_LIST_DIR}/../Programmer/${DIR_NAME}/Programmer${WIN_EXE}")
include("${CMAKE_CURRENT_LIST_DIR}/../../system/src/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/../../cores/riscduinov/CMakeLists.txt")
# if(NOT ${USE_SYSTEM_STATIC_LIBRARY})
#     message("USE_SYSTEM_STATIC_LIBRARY = ${USE_SYSTEM_STATIC_LIBRARY}")
#     include("${CMAKE_CURRENT_LIST_DIR}/../../Hardware/software/system/src/CMakeLists.txt")
# endif()

add_custom_command(OUTPUT Elf2Mem PRE_BUILD COMMAND ${PROGRAM_TOOL} -a ${PROJECT_SOURCE_DIR}/bin/${CMAKE_PROJECT_NAME}.elf -LHex)

add_custom_target(${CMAKE_PROJECT_NAME}.mem DEPENDS Elf2Mem)

add_custom_command(OUTPUT Elf2Mif PRE_BUILD COMMAND ${PROGRAM_TOOL} -a ${PROJECT_SOURCE_DIR}/bin/${CMAKE_PROJECT_NAME}.elf -AMif)

add_custom_target(${CMAKE_PROJECT_NAME}.mif DEPENDS Elf2Mif)

# Specify the command to execute to copy the .elf to .bin
add_custom_command(OUTPUT Elf2Bin PRE_BUILD COMMAND ${CMAKE_OBJCOPY_COMPILER} ${CMAKE_OBJCOPY_FLAGS} -O binary ${PROJECT_SOURCE_DIR}/bin/${CMAKE_PROJECT_NAME}.elf ${PROJECT_SOURCE_DIR}/bin/${CMAKE_PROJECT_NAME}.bin)
# Specify the rule to the makefile that will execute the custom command
add_custom_target(${CMAKE_PROJECT_NAME}.bin DEPENDS Elf2Bin)

# Specify the command to execute to copy the .elf to .srec
add_custom_command(OUTPUT Elf2Srec PRE_BUILD COMMAND ${CMAKE_OBJCOPY_COMPILER} ${CMAKE_OBJCOPY_FLAGS} -O srec ${PROJECT_SOURCE_DIR}/bin/${CMAKE_PROJECT_NAME}.elf ${PROJECT_SOURCE_DIR}/bin/${CMAKE_PROJECT_NAME}.srec)
# Specify the rule to the makefile that will execute the custom command
add_custom_target(${CMAKE_PROJECT_NAME}.srec DEPENDS Elf2Srec)

# Specify the command to execute to copy the .elf to .hex
add_custom_command(OUTPUT Elf2Hex PRE_BUILD COMMAND ${CMAKE_OBJCOPY_COMPILER} ${CMAKE_OBJCOPY_FLAGS} -O ihex ${PROJECT_SOURCE_DIR}/bin/${CMAKE_PROJECT_NAME}.elf ${PROJECT_SOURCE_DIR}/bin/${CMAKE_PROJECT_NAME}.hex)
# Specify the rule to the makefile that will execute the custom command
add_custom_target(${CMAKE_PROJECT_NAME}.hex DEPENDS Elf2Hex)

# Specify the command to execute to program the FPGA
add_custom_target(PROGRAM_FPGA_ROM COMMAND ${PROGRAM_TOOL} -p ${SERIAL_PORT} -a ${PROJECT_SOURCE_DIR}/bin/${CMAKE_PROJECT_NAME}.elf ${VERBOSE})

add_custom_target(PROGRAM_FPGA_RAM COMMAND ${PROGRAM_TOOL} -p ${SERIAL_PORT} -a ${PROJECT_SOURCE_DIR}/bin/${CMAKE_PROJECT_NAME}.elf -r ${VERBOSE})

add_custom_target(SHOW_SIZE COMMAND ${CMAKE_SIZE} ${CMAKE_SIZE_FLAGS} ${PROJECT_SOURCE_DIR}/bin/${CMAKE_PROJECT_NAME}.elf)