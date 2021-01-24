set(ArduinoLib_src 
    "${CMAKE_CURRENT_LIST_DIR}/HardwareSerial.cpp" 
    "${CMAKE_CURRENT_LIST_DIR}/Print.cpp" 
    "${CMAKE_CURRENT_LIST_DIR}/Stream.cpp" 
    "${CMAKE_CURRENT_LIST_DIR}/wiring_digital.c" 
    "${CMAKE_CURRENT_LIST_DIR}/wiring_shift.cpp" 
    "${CMAKE_CURRENT_LIST_DIR}/WMath.cpp" 
    "${CMAKE_CURRENT_LIST_DIR}/WString.cpp" 
    "${CMAKE_CURRENT_LIST_DIR}/itoa.c"
)
# add_library(ArduinoLib STATIC ${ArduinoLib_src})