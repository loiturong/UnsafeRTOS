# UnSafeRTOS

## Current Target

### Target Family
This OS targets STM32 microcontrollers, built on top of STM32Cube HAL.

### Primary Development Board

* STM32F411CEU6 (Black Pill)

### MCU Family Focus

* STM32 family (primarily Cortex-M based MCUs)

The project is currently designed around STM32 devices and CubeMX HAL integration.
Future portability to other STM32 series — and potentially non-ST ARM Cortex-M boards — is possible, but multi-target support is not yet implemented.

## Philosophy

UnsafeRTOS is a learning-focused RTOS project inspired by FreeRTOS and general real-time operating system design philosophy.

This project attempts to reimplement and study many of the core concepts commonly found in modern RTOS designs, including:

* Deterministic scheduling
* Context switching
* Task synchronization
* Timing guarantees
* Critical section management
* Priority-based execution
* Interrupt-aware kernel behavior

Core principles:

* Readability and Optimization only when possible
* Educational value
* Incremental and experimental development
* Minimal dependencies
* Learning through implementation

## Toolchain

### Environment

* STM32CubeMX
* ARM GCC Toolchain
* OpenOCD
* GDB
* VSCode / Nvim

### Build System

CubeMX-generated projects with HAL integration.

The project is compiled and built using Makefile script.

## License

This project is licensed under the GNU General Public License v3.0.

See the [LICENSE](./LICENSE) file for details.
