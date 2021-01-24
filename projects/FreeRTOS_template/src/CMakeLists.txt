set(sources
    main.c
)
set(FreeRTOSKernel_src 
    "../FreeRTOSKernel/portable/GCC/RISC-V/port.c"
    "../FreeRTOSKernel/portable/MemMang/heap_3.c"
    "../FreeRTOSKernel/portable/GCC/RISC-V/portASM.S" 
    "../FreeRTOSKernel/croutine.c"
    "../FreeRTOSKernel/event_groups.c" 
    "../FreeRTOSKernel/list.c"
    "../FreeRTOSKernel/queue.c" 
    "../FreeRTOSKernel/stream_buffer.c"
    "../FreeRTOSKernel/tasks.c"
    "../FreeRTOSKernel/timers.c"
    )
add_executable(${CMAKE_PROJECT_NAME} ${sources} ${crt0_src} ${riscvSoC_src} ${ArduinoLib_src} ${FreeRTOSKernel_src})

# target_link_libraries(${ApplicationName} FreeRTOSKernel)
# target_link_libraries(${ApplicationName} crt0 riscvSoC ArduinoLib)
# message(STATUS "crt0_src=${crt0_src}")