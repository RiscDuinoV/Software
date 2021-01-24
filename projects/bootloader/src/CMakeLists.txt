set(sources
	main.c flash.c
)
add_executable(${CMAKE_PROJECT_NAME} ${sources} ${crt0_src} ${riscvSoC_src})