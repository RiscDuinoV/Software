include_directories(FreeRTOSKernel/FreeRTOS-Kernel/include)
include_directories(FreeRTOSKernel/FreeRTOS-Kernel/portable/GCC/RISC-V)
include_directories(FreeRTOSKernel/FreeRTOS-Kernel/portable/GCC/RISC-V/chip_specific_extensions/RV32I_CLINT_no_extensions)

set(freertos_src 
    "FreeRTOSKernel/FreeRTOS-Kernel/portable/GCC/RISC-V/port.c"
    "FreeRTOSKernel/FreeRTOS-Kernel/portable/MemMang/heap_4.c"
    "FreeRTOSKernel/FreeRTOS-Kernel/portable/GCC/RISC-V/portASM.S" 
    "FreeRTOSKernel/FreeRTOS-Kernel/croutine.c"
    "FreeRTOSKernel/FreeRTOS-Kernel/event_groups.c" 
    "FreeRTOSKernel/FreeRTOS-Kernel/list.c"
    "FreeRTOSKernel/FreeRTOS-Kernel/queue.c" 
    "FreeRTOSKernel/FreeRTOS-Kernel/stream_buffer.c"
    "FreeRTOSKernel/FreeRTOS-Kernel/tasks.c"
    "FreeRTOSKernel/FreeRTOS-Kernel/timers.c"
    )

# FreeRTOS Kernel
add_library(freertos_kernel ${freertos_src})
add_definitions(-DportasmHANDLE_INTERRUPT=interrupt_handler -DTRAP_ENTRY=freertos_risc_v_trap_handler)
target_link_libraries(${CMAKE_PROJECT_NAME} freertos_kernel)