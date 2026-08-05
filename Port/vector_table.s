.syntax unified
.thumb
.section .text.exceptions

.type NMI_Handler, %function
NMI_Handler:
	b NMI_Handler

.type HardFault_Handler, %function
HardFault_Handler:
	b HardFault_Handler

.type MemManage_Handler, %function
MemManage_Handler:
	b MemManage_Handler

.type BusFault_Handler, %function
BusFault_Handler:
	b BusFault_Handler

.type UsageFault_Handler, %function
UsageFault_Handler:
	b UsageFault_Handler

.type DebugMonitor_Handler, %function
DebugMonitor_Handler:
	b DebugMonitor_Handler

.section .exception_vector_table, "a", %progbits
.type  system_exception_vector_table, %object
.global system_exception_vector_table

/* ARM fetch first 2 word for its hardware startup sequence */
/* also place the interrupt vector table in this region */
.system_exception_vector_table:
	.word _sstack_top
	.word Reset_Handler
	.word NMI_Handler
	.word HardFault_Handler
	.word MemManage_Handler
	.word BusFault_Handler
	.word UsageFault_Handler
	.word 0x00
	.word 0x00
	.word 0x00
	.word 0x00
	.word SVCall_Handler
	.word DebugMonitor_Handler
	.word 0x00
	.word PendSV_Handler
	.word SysTick_Handler
