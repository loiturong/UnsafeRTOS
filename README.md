# UnsafeRTOS

A minimal preemptive RTOS built from the register level on STM32F4,
with no HAL/CubeMX abstraction.

## Goal

Understand how an RTOS actually works — scheduler, context switching,
interrupts.

## Programming References

- RM0383 Reference manual - STM32F411xC/E advanced Arm®-based 32-bit MCUs
- STM32F411xC STM32F411xE - Datasheet
- Arm® Cortex®-M4 Processor - Technical Reference Manual Revision: r0p1
- Arm® v7-M Architecture - Reference Manual
- PM0214 Programming manual - STM32 Cortex®-M4 MCUs and MPUs programming manual

## Memory Layout

Memory Layout is design according to datasheet, with FLASH start at `0x08000000` and 
RAM start at `0x20000000`. The table below is show in a reverse order.

| Region | Detail | Placement |
|---|---|---|
| 0x08000000 | Start of Flash | Firmware |
| 0x20000000 | Start of RAM | static data, bss region |
| - | after data region | user heap |
| - | remaining space | heap grows up, stack grows down |
| 0x2001F000 | - | System stack bottom |
| 0x20020000 | End of RAM | System stack top |

## Status

- ~~Board bring-up phase~~
- ~~Setup NVIC~~
- Setup PendSV and SVCall for kernel initialization

Testing on emulation

## License

This project is licensed under the GNU General Public License v3.0.

See the [LICENSE](./LICENSE) file for details.
