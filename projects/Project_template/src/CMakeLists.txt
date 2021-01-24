set(sources
    main.c                                                    # Add here all your files to compile
)                                                                       
add_executable(${CMAKE_PROJECT_NAME} ${sources} ${crt0_src} ${riscvSoC_src} ${ArduinoLib_src})                           # Compile your code
target_link_libraries(${ApplicationName} MaLibrairie)                   # Link Static librarie from lib folder
# target_link_libraries(${ApplicationName} crt0 riscvSoC ArduinoLib)
