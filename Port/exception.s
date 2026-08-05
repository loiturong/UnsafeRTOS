.syntax unified

.section .text.exceptions
.global PendSV_Handler
PendSV_Handler:
	bx lr

.global SVCall_Handler
SVCall_Handler:
	ldr r0, =default_task_stack
	mrs r0, psp
	/* setup task context */
	sub r0, 4
	mov r1, 0x01000000
	str r1, [r0]	// xSPR

	sub r0, 4
	ldr r1, =default_task
	str r1, [r0]	// PC
	
	sub r0, 4
	mov r1, 0x00
	str r1, [r0]	// LR

	sub r0, 20

	/* We are just running from process stack, trust */
	mov lr, 0xFFFFFFFD
	bx lr
