# UnsafeRTOS - Kernel

Simple RTOS kernel with no dependecies.

## Goal

Understand how RTOS works — scheduler, context switching, interrupts.

## Usesage

This project is provided with a [CMakeLists.txt](./CMakeLists.txt), which provides a
static library. 

Kernel provide its public api via: [Include/rtos_kernel.h](./Include/rtos_kernel.h)

## Programming References

- Arm® Cortex®-M4 Processor - Technical Reference Manual Revision: r0p1
- Arm® v7-M Architecture - Reference Manual
- PM0214 Programming manual - STM32 Cortex®-M4 MCUs and MPUs programming manual
- Cortex-M4(F) Lazy Stacking and Context Switching - Application Note 298

## Requirements for Application

Application must setup its environment with:
- Board specific Vector Table
- UnsafeRTOS uses SysTick, PendSV, and SVCall for its operation, so Application should not implement this
- UnsafeRTOS implement a memory management, Application must provide a pointer to where heap can start operate (via linker)

## Status
Early stage.

Testing on emulator.

## License

This project is licensed under the GNU General Public License v3.0.

See the [LICENSE](./LICENSE) file for details.
