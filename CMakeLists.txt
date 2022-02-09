file(GLOB arduino_src 
    "${CMAKE_CURRENT_LIST_DIR}/cores/riscduinov/*.c"
    "${CMAKE_CURRENT_LIST_DIR}/cores/riscduinov/*.cpp")

list (REMOVE_ITEM arduino_src 
    "${CMAKE_CURRENT_LIST_DIR}/cores/riscduinov/src_wrapper.c"
    "${CMAKE_CURRENT_LIST_DIR}/cores/riscduinov/main.cpp")

file(GLOB crt0_src 
    "${CMAKE_CURRENT_LIST_DIR}/system/src/riscv/*.S")

file(GLOB xtr_soc_src
    "${CMAKE_CURRENT_LIST_DIR}/system/src/riscv/*.c" 
    "${CMAKE_CURRENT_LIST_DIR}/system/src/*.c")