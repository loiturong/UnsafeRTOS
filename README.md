# UnsafeRTOS

A minimal RTOS built from the register level on STM32F4,
with no HAL/CubeMX abstraction.
This project include ARM's CMSIS headers.

## Goal

Understand how an RTOS actually works — scheduler, context switching,
interrupts.

## Build & Run

### Prerequisites
- arm-none-eabi-gcc (tested with v16.1.0)
- QEMU if running on an emulator
- Build system using Cmake
- test script is written in Makefile

### Configure
```sh
cmake -B build -DCMAKE_BUILD_TYPE=Release
```
or build with debug
```sh
cmake -B build -DCMAKE_BUILD_TYPE=Debug
```

### Build
```sh
cmake --build build
```

### Run (emulator)
```sh
make emu-run
```

### Run (hardware)
Not yet validated.

## Programming References

- RM0383 Reference manual - STM32F411xC/E advanced Arm®-based 32-bit MCUs
- STM32F411xC STM32F411xE - Datasheet
- Arm® Cortex®-M4 Processor - Technical Reference Manual Revision: r0p1
- Arm® v7-M Architecture - Reference Manual
- PM0214 Programming manual - STM32 Cortex®-M4 MCUs and MPUs programming manual
- Cortex-M4(F) Lazy Stacking and Context Switching - Application Note 298

## Memory Layout

Memory Layout is designed according to datasheet, 
with FLASH start at `0x08000000` and 
RAM start at `0x20000000`. 
The table below is shown in a reverse order.

| Region | Detail | Placement |
|---|---|---|
| 0x08000000 | Start of Flash | Firmware |
| 0x20000000 | Start of RAM | static data, bss region |
| - | after data region | user heap |
| - | remaining space | heap grows up, stack grows down |
| 0x2001F000 | - | System stack bottom |
| 0x20020000 | End of RAM | System stack top |

## Status
Early stage.

Testing on emulator.

## License

This project is licensed under the GNU General Public License v3.0.

See the [LICENSE](./LICENSE) file for details.

## Third-Party Code

This project includes ARM's CMSIS headers for Cortex-M core register access.

CMSIS is licensed separately by ARM — see [Port/CMSIS/LICENSE](./Port/CMSIS/).
