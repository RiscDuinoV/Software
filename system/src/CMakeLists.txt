add_library(crt0 STATIC riscv/start.S)

add_library(crt0FreeRTOS STATIC riscv/start_FreeRTOS.S)

add_library(riscvSoC STATIC 
    riscv/mtime.c sio.c interrupt_controller.c i2c.c gpio.c
)

# add_library(syscall STATIC syscall.c)

#add_library(c 
#    assert.c atoi.c diskio.c div.c div64.c fatfs.c file.c gets.c malloc.c memcmp.c memcpy.c memmove.c memset.c mul.c printf.c qsort.c random.c sdcard.c sio_poll.c spi.c sprintf.c strcasecmp.c strcpy.c strncpy.c strstr.c strtol.c
#)

#add_library(cint 
#    assert.c atoi.c diskio.c div.c div64.c fatfs.c file.c gets.c malloc.c memcmp.c memcpy.c memmove.c memset.c mul.c printf.c qsort.c random.c sdcard.c sio_poll.c spi.c sprintf.c strcasecmp.c strcpy.c strncpy.c strstr.c strtol.c float/adddf3.c float/addsf3.c float/ashldi3.c float/clzsi2.c float/comparedf2.c float/comparesf2.c float/divdf3.c float/divsf3.c float/extendsfdf2.c float/fixdfsi.c float/fixsfsi.c float/fixunsdfdi.c float/fixunsdfsi.c float/fixunssfsi.c float/floatsidf.c float/floatsisf.c float/floatundidf.c float/floatundisf.c float/floatunsidf.c float/floatunsisf.c float/lshrdi3.c float/muldf3.c float/mulsf3.c float/negdf2.c float/negsf2.c float/subdf3.c float/subsf3.c float/truncdfsf2.c
#)

#add_library(m
#    math/scalbn.c math/pow.c math/isnan.c math/fabs.c math/floor.c math/log.c math/atan.c math/cos.c math/acos.c math/copysignf.c math/fmod.c math/sinhf.c math/sin.c math/sqrt.c math/asin.c math/exp.c math/cosf.c math/sinf.c math/acosf.c math/asinf.c math/atanf.c math/expf.c math/fabsf.c math/fmodf.c math/floorf.c math/logf.c math/powf.c math/sqrtf.c math/ceilf.c math/expm1.c math/coshf.c math/modff.c math/atan2f.c math/log10f.c math/tanhf.c math/log2f.c math/tanf.c math/erff.c math/atanhf.c math/acoshf.c math/asinhf.c math/expm1f.c math/log1pf.c math/frexpf.c math/isinf.c math/isfinite.c math/scalbnf.c math/log2.c math/log10.c math/cosh.c math/sinh.c math/modf.c math/ceil.c math/erf.c math/frexp.c math/atan2.c math/acosh.c math/log1p.c math/atanh.c math/asinh.c math/tanh.c math/tan.c
#)

#target_compile_definitions(c PRIVATE NO_PRINTF_FLOAT)
#target_compile_definitions(cint PRIVATE NO_PRINTF_FLOAT)