file(GLOB ArduinoLib_src 
    "${CMAKE_CURRENT_LIST_DIR}/*.c"
    "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

list (REMOVE_ITEM ArduinoLib_src 
    "${CMAKE_CURRENT_LIST_DIR}/src_wrapper.c"
    "${CMAKE_CURRENT_LIST_DIR}/main.cpp")