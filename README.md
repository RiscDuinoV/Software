# Software
This repository contains basic projects and system libraries, to communicate with RiscDuinoV Hardware. System libraries source code is located [here](https://github.com/RiscDuinoV/Software/tree/master/system).

System libraries have been ported to Arduino Framework so that you can use most of Arduino features through the Arduino IDE.

## Getting Started
To send a program, go to [projects/Project_template](https://github.com/RiscDuinoV/Software/tree/master/projects/Project_template) compile the program and then send it to the RiscDuinoV. The compiling instructions are described in [projects](https://github.com/RiscDuinoV/Software/tree/master/projects) Open a terminal with the configuration 115200 8N1 and you should see an **Hello, World** message in the terminal.

To create your own RISC-V project you can follow the example of [Project_Template](https://github.com/RiscDuinoV/Software/tree/master/projects/Project_template) to configure your application.

You can use also Eclipse to create your own RISC-V, but you must configure the flags manually. In [tools/cmake/Toolchain-Script.cmake](https://github.com/RiscDuinoV/Software/tree/master/tools/cmake/Toolchain-Script.cmake), you can find all flags used to compile a RISC-V project.

## Compiling with Arduino IDE

If you don't want to read all the tutorial from **projects** to learn how to compile a simple program, you can use Arduino IDE to compile a program and send directly to the RiscDuinoV.

First go to File &rarr; Preferences &rarr; Additional Boards Manager URLs and copy the following link :

    https://github.com/RiscDuinoV/RiscDuinoV-Bin/raw/master/package_RiscDuinoV_index.json

Then go to Tools &rarr; Board &rarr; Boards Manager, search and install **RiscDuinoV** board. Then after installing, on Tools &rarr; Board, you should be able to pick **RiscDuinoV** board and compile your code like an Arduino.