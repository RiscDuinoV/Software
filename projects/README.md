# Compiling a project

Here you can find a basic RISC-V projects templates that you can use to build your custom application.

## Requirements

### Installing CMake

Donwload the latest version of [CMake](https://cmake.org/download/).

On Linux :  

    $ sudo apt-get install cmake

### Installing GNU Makefiles or Ninja

- <http://gnuwin32.sourceforge.net/packages/make.htm>
- <https://github.com/ninja-build/ninja/releases>
  
On Linux :  

    $ sudo apt-get install make
or

    $ sudo apt-get install ninja-build

### Installing RISC-V Compiler

Check `README.md` file from [tools](https://github.com/RiscDuinoV/Software/tree/master/tools).

## Compiling

Go to the root of your project and then type :

    $ cmake -G "your generator"

Your generator can be :

- Unix Makefiles
- Ninja

You should see the following message :

    $ cmake -G "your generator"
    ...
    -- Configuring done
    -- Generating done
    -- Build files have been written to: /home/...

After configuring and generating your makefiles, you should be able to compile your project. To compile type :

    $ make 
or

    $ ninja

To see all available options type :

    $ make help
or

    $ ninja help

## Executing

If you have SoC with a bootloader you must be able to program the RISC-V directly through a Serial port. 
```
$ cmake -DSERIAL_PORT=/dev/ttyUSB0
```
You can also set as a variable on **CMakeLists.txt** file located on the root before including **Options.cmake**.
```cmake
set(SERIAL_PORT "/dev/ttyUSB0")
```
After selecting the Serial Port you can then program the RISC-V with the following commands :

    $ make PROGRAM_RAM
    # or
    $ make PROGRAM_ROM

If you have an SPI Flash and if you map the SPI0 you can use it to store multiple applications (Feature).  

You can also create memory initialization file to initialize FPGA BRAM with your application.

    $ make MyApp.mem # Generate Lattice initialization file
    $ make MyApp.mif # Generate generic initialization file

Then on the top VHDL file specify the path to this initialization file

You can use the JTAG to send your application. You must synthesize the RiscDuinoV with a JTAG and then send it through GDB and OpenOCD see [here]().

## Using the bootloader

Two versions of bootloader are available :

- Loads your code in RAM
- Loads your code in RAM and SPI FLASH.
  
On the Top Level file from the RTL project, you must set **C_Boottrap** to **true**. To avoid bootloader corruption, you can protect 1K or 2K of RAM where the bootloader is stored by setting **C_ProtectRam**. If you don't want any protection, set it to 0. If you're using the RiscDuinoV with the JTAG set **C_ProtectRam** to **0** and **C_BootTrap** to **false**.

To build the bootloader go to the project [bootloader](https://github.com/RiscDuinoV/Software/tree/master/projects/bootloader). Once there just follow the [Compiling](#Compiling) section and then you must generate a initialization file depending on your FPGA platform (Generic &rarr; .mif, Lattice &rarr; .mem) see [Executing](#Executing) section.

## Using system libraries
Don't forget to add the system libaries and Arduino Framework when you call **add_executable** on your CMakeLists.txt.
```cmake
add_executable(${CMAKE_PROJECT_NAME} ${sources} ${crt0_src} ${riscvSoC_src} ${ArduinoLib_src})
```
**crt0_src** is very important. It's the one who starts your application.

This variables are set by [Options.cmake](https://github.com/RiscDuinoV/Software/tree/master/tools/cmake/Options.cmake). Make sure you include **Options.cmake** before calling **add_executable**.