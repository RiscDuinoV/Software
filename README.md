# Software

System libraries are available in this repository. Source system C libraries are available in **system** and Arduino system C++ libraries are available in **Cores/riscduinov**.

## Using system libraries

Before being able to compile a project that contains system libraries, you must before compile the library to be able to used them in you're project. You just need to compile them once because the script in Tools/Compiler/Toolchain-Script.cmake is going to use their binaries and link them with your application.

## Compiling system libraries

To compile the system libraries, you'll need first to install CMake and other dependencies. Check [here](https://github.com/RiscDuinoV/RISCV/tree/master/RiscV_Projects)

Once you've install all dependencies and CMake, you'll need to configure the project and then compile.

```sh
$ cmake -G "your generator"
...
-- Configuring done
-- Generating done
-- Build files have been written to: /home/...
$ make
...
# or
$ ninja
...
```

The library binaries can be found at **system/lib/riscv**.
