[![License Apache--2.0](https://img.shields.io/badge/License-Apache--2.0-green?label=License)](https://github.com/Arm-Examples/Hello_NUCLEO-G474RE/blob/main/LICENSE)
[![Build and Execution Test](https://img.shields.io/github/actions/workflow/status/Arm-Examples/Hello_NUCLEO-G474RE/build.yml?logo=arm&logoColor=0091bd&label=Build%20and%20Execution%20Test)](./.github/workflows/build.yml)
[![Example workflow](https://img.shields.io/github/actions/workflow/status/Arm-Examples/Hello_NUCLEO-G474RE/ci.yml?logo=arm&logoColor=0091bd&label=Example%20Publishable)](https://www.keil.arm.com/)
[![CMSIS Compliance](https://img.shields.io/github/actions/workflow/status/Arm-Examples/Hello_NUCLEO-G474RE/verify.yml?logo=arm&logoColor=0091bd&label=CMSIS%20Compliance)](https://www.keil.arm.com/cmsis) 

# Hello example for NUCLEO-G474RE

Simple "Hello World" example for
[**STMicroelectronics NUCLEO-G474RE**](https://www.st.com/en/evaluation-tools/nucleo-g474re.html) development board.
This example prints `Hello World` and a counter value via the standard output which is routed to the debug console
through a virtual COM port.

## Prerequisites

The following tools need to be installed on your machine:

- [CMSIS-Toolbox v2.13.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or newer.
- [Arm Compiler for Embedded](https://developer.arm.com/Tools%20and%20Software/Arm%20Compiler%20for%20Embedded)
  (automatically installed via vcpkg when using Visual Studio Code).
- [Microsoft Visual Studio Code](https://code.visualstudio.com/download) with Keil Studio Pack extension.

## Build the example

### Using Visual Studio Code with extensions

Required tools described in file `vcpkg-configuration.json` should be automatically installed by vcpkg. You can see the
status of vcpkg in the status bar.

Required CMSIS packs need to be also installed. In case a required pack is missing, a notification window will pop-up
to install the missing pack.

Open the 'CMSIS' view from the side bar, select desired 'Build Type' and press the 'Build' button.

### Using Command Line Interface (CLI)

Download required packs (not required when the packs are already available) by executing the following commands:

```sh
csolution list packs -s hello.csolution.yml -m > packs.txt
cpackget update-index
cpackget add -f packs.txt
```

Build the project by executing the following command:

```sh
cbuild hello.csolution.yml
```

## Run the example

### Run in Visual Studio Code

- Connect the board's ST-LINK USB to the PC (provides also power).
- Open the 'CMSIS' view from the side bar:
    - Press the 'Run' button and wait until the image is programmed and starts running.

### Using Drag-and-drop programming or external programmer and terminal

- Connect the board's ST-LINK USB to the PC (provides also power).
- Program the image (.hex) using drag-and-drop programming or use an external programmer.
- Open a terminal on the PC and connect to the board's serial port with 115200 baud rate.
- Observe the terminal output.

## Debug the example

Before starting to debug the application, make sure that you have gone through the steps as described in the
[run the application](#run-the-application) section.

### Debug in Visual Studio Code

Open the **CMSIS** view from the side bar and press the **Debug** button. In the **Debug** view, use the
**SERIAL MONITOR** to connect to the board's serial port with 115200 baud rate and observe the output.
