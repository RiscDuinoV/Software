# Tools

## Installing the toolchain

Before being able to compile, you'll need first to download the RISC-V compilers from SiFive. The prebuilt toolchain can be found here :

- <https://www.sifive.com/software/> &rarr; SiFive GNU Embedded Toolchain

Install them here:  

- Tools/toolchain

If you want to install them elsewhere see below.

## Toolchain already installed

If you have already the compilers installed, on CMakeLists.txt before setting **CMAKE_TOOLCHAIN_FILE** set:

```CMake
set(TOOLCHAIN_PATH "PATH/TO/THE/TOOLCHAIN")
```