set(crt0_src 
    "${CMAKE_CURRENT_LIST_DIR}/riscv/start.S" 
    "${CMAKE_CURRENT_LIST_DIR}/riscv/interrupt_handler.S"
)
set(riscvSoC_src
    "${CMAKE_CURRENT_LIST_DIR}/riscv/mtime.c" 
    "${CMAKE_CURRENT_LIST_DIR}/sio.c"
    "${CMAKE_CURRENT_LIST_DIR}/interrupt_controller.c" 
    "${CMAKE_CURRENT_LIST_DIR}/i2c.c"
    "${CMAKE_CURRENT_LIST_DIR}/gpio.c"
    "${CMAKE_CURRENT_LIST_DIR}/syscall.c"
    "${CMAKE_CURRENT_LIST_DIR}/sysmem.c"
)
# add_library(crt0 STATIC ${crt0_src})
# 
# add_library(riscvSoC STATIC ${riscvSoC_src})