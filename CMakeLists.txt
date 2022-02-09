file(GLOB arduino_src 
    "${CMAKE_CURRENT_LIST_DIR}/cores/xtrduino/*.c"
    "${CMAKE_CURRENT_LIST_DIR}/cores/xtrduino/*.cpp")

list (REMOVE_ITEM arduino_src 
    "${CMAKE_CURRENT_LIST_DIR}/cores/xtrduino/src_wrapper.c"
    "${CMAKE_CURRENT_LIST_DIR}/cores/xtrduino/main.cpp")

file(GLOB crt0_src 
    "${CMAKE_CURRENT_LIST_DIR}/system/src/riscv/*.S")

file(GLOB xtr_soc_src
    "${CMAKE_CURRENT_LIST_DIR}/system/src/riscv/*.c" 
    "${CMAKE_CURRENT_LIST_DIR}/system/src/*.c")