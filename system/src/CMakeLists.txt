add_library(crt0 STATIC riscv/start.S riscv/interrupt_handler.S)

add_library(riscvSoC STATIC 
    riscv/mtime.c sio.c interrupt_controller.c i2c.c gpio.c
)