# UnsafeRTOS - Kernel

Simple RTOS kernel with no dependecies.

## Goal

Understand how RTOS works.

## Project Structure
```sh
UnsafeRTOS-Kernel
├── Arch
│   └── M4
│       ├── Include
│       ├── exception.s
│       ├── port.c
│       └── syscall.s
├── CMakeLists.txt
├── Include
│   ├── heap.h
│   ├── kernel.h
│   ├── queue.h
│   ├── scheduler.h
│   ├── stack.h
│   └── task.h
├── LICENSE
├── README.md
├── heap.c
├── kernel.c
├── queue.c
├── scheduler.c
├── stack.c
└── task.c
```

## Usage

This project is provided with a [CMakeLists.txt](./CMakeLists.txt), which provides a
static library. 

Kernel provide its public api via: [Include/kernel.h](./Include/kernel.h)

## Programming References

Technical Documentations:
- Arm® Cortex®-M4 Processor - Technical Reference Manual Revision: r0p1
- Arm® v7-M Architecture - Reference Manual
- PM0214 Programming manual - STM32 Cortex®-M4 MCUs and MPUs programming manual
- Cortex-M4(F) Lazy Stacking and Context Switching - Application Note 298

Design Consideration:
- FreeRTOS Kernel Source
- SuperTinyKernel RTOS Source

## About Memory Management

Kernel now implemented with zero dynamic allocation task create.

## Example usage
create task with static allocation.
```c
#include <UnsafeRTOS_Kernel/Include/kernel.h>

/* Task A */
static process_control_block_t task_a_block;
char task_a_stack[256 * 4];
static uint32_t counter_a = 0;
void task_a(void) {
	for(;;) { 
		counter_a++;
	    task_delay(NULL, 500);  // 1 Ticks = 1 MS
	}
}

/* Task B */
static kernel_handle_t task_b_block;
static char task_b_stack[256 * 4];
static uint32_t counter_b = 0;
void task_b(void) {
	for(;;) { 
        counter_b++;
        task_delay(NULL, 750);
    }
}

void main()
{
    BoardSetup();
	ExceptionSetup();
	uint32_t ticks =  BOARD_FREQ * 1 / 1000;
	SysTick_Config(ticks);
	
	task_create_static(&task_a_block, (uintptr_t *)task_a_stack, 32 * 4, (void *)task_a);
	task_create_static(&task_b_block, (uintptr_t *)task_b_stack, 32 * 4, (void *)task_b);
    
    EnableSysTickINT();
    EnableInt();

	kernel_start();     // Syscall
	while(1);
}

```

Kernel tested design (Cortex-M4 - ARMv7M):

| Exception | Priority |
|---|---|
| Reset | -3 (fixed) |
| Hardfault | -2 (fixed) |
| Non-Masked | -1 (fixed) |
| MemoryManagement | 0 |
| BusFault | 1 |
| UsageFault | 2 |
| DebugMonitor | 3 |
| SVCall | 4 |
| PendSV | 0xFF (Refers to Manufacture's prior_bit or use CMSIS) |
| SysTick | 0xFF |
| EXTI | 0xFE (no interrupt tested yet) |


## Status
First view of Concurrency.
- Multiple Task calling delay at the same time (all modifying task list and wait list)
- SysTick preempted mid delay function (which also modifying task list)

Testing on emulator.

## License

This project is licensed under the GNU General Public License v3.0.

See the [LICENSE](./LICENSE) file for details.
