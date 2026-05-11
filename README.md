# UnSafeRTOS

## Goals

* Build a minimal but practical RTOS from scratch
* Understand how real embedded kernels work internally
* Learn Cortex-M exception handling and context switching
* Provide a clean architecture for experimentation and extension
* Maintain compatibility with STM32CubeMX generated projects

---

## Current Target

### Target Family
This OS targets STM32 microcontrollers, built on top of STM32Cube HAL.

### Primary Development Board

* STM32F411CEU6 (`Black Pill`)

### MCU Family Focus

* STM32 family (primarily Cortex-M based MCUs)

The project is currently designed around STM32 devices and CubeMX HAL integration.
Future portability to other STM32 series — and potentially non-ST ARM Cortex-M boards — is possible, but multi-target support is not yet implemented.

---

## Design Philosophy

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

* Readability and Optimization when possible
* Educational value
* Incremental and experimental development
* Minimal dependencies
* Learning through implementation

---

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

---

## Status

Early development phase.

The first milestone is bringing up:

1. Basic scheduler
2. Task switching
3. SysTick integration
4. Stable context switching on STM32F411CEU6

---

## Learning Objectives

This project exists primarily as a systems programming and embedded learning platform.

Topics explored include:

* ARM Cortex-M internals
* RTOS architecture
* Embedded memory management
* Interrupt-driven systems
* Cooperative vs preemptive multitasking
* Low-level debugging
* Linker scripts and startup code

---

## License

This project is licensed under the GNU General Public License v3.0.
See the [LICENSE](./LICENSE) file for details.
