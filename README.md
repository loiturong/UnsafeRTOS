# UnsafeRTOS - Kernel

Simple RTOS kernel with no dependecies.

## Goal

Understand how RTOS works — scheduler, context switching, interrupts.

## Usage

This project is provided with a [CMakeLists.txt](./CMakeLists.txt), which provides a
static library. 

Kernel provide its public api via: [Include/rtos_kernel.h](./Include/rtos_kernel.h)

## Programming References

Technical Documentations:
- Arm® Cortex®-M4 Processor - Technical Reference Manual Revision: r0p1
- Arm® v7-M Architecture - Reference Manual
- PM0214 Programming manual - STM32 Cortex®-M4 MCUs and MPUs programming manual
- Cortex-M4(F) Lazy Stacking and Context Switching - Application Note 298

Design Consideration:
- FreeRTOS Kernel Source
- SuperTinyKernel RTOS (Idea of fixed size free list)

## Requirements for Application

Application must setup its environment with:
- Board specific Vector Table
- UnsafeRTOS uses SysTick, PendSV, and SVCall for its operation, so Application should not implement this
- UnsafeRTOS implement a memory management, Application must provide a pointer to where heap can start operate (via linker)

## About Memory Management

Kernel implement a fixed size freelist allocator for minimal overhead. 
A size of 128 bytes (32 words), and HEAP size of 8KB as heap default configuration.
Any data structure occupies over the config size should use static allocation instead.

## Status
Early stage.

Testing on emulator.

## License

This project is licensed under the GNU General Public License v3.0.

See the [LICENSE](./LICENSE) file for details.
