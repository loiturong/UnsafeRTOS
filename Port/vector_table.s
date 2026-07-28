.syntax unified

.section .text.exceptions
/* Default execption handler with infinite loop */
Default_Handler:
	b Default_Handler

.weak MNI_Handler
.weak HardFault_Handler
.weak MemManage_Handler
.weak BusFault_Handler
.weak UsageFault_Handler
.weak SVCall_Handler
.weak DebugMonitor_Handler
.weak PendSV_Handler
.weak SysTick_Handler

/* Temporary */
.thumb_set MNI_Handler, Default_Handler
.thumb_set HardFault_Handler, Default_Handler
.thumb_set MemManage_Handler, Default_Handler
.thumb_set BusFault_Handler, Default_Handler
.thumb_set UsageFault_Handler, Default_Handler
.thumb_set SVCall_Handler, Default_Handler
.thumb_set DebugMonitor_Handler, Default_Handler
.thumb_set PendSV_Handler, Default_Handler
.thumb_set SysTick_Handler, Default_Handler

.section .interrupt_vector_table
.type  vector_table, %object
.global vector_table

/* ARM fetch first 2 word for its hardware startup sequence */
/* also place the interrupt vector table in this region */
.vector_table:
	.word _sstack_top
	.word Reset_Handler
	.word MNI_Handler
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
	.word 0x0
	.word PendSV_Handler
	.word SysTick_Handler
	/* Other added latter */
	.rept 240
	.word Default_Handler
	.endr
