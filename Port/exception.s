.syntax unified

.section .text.exceptions
.global PendSV_Handler
.type PendSV_Handler, %function
PendSV_Handler:
	bx lr

.global SVCall_Handler
.type SVCall_Handler, %function
SVCall_Handler:
	/* Save kernel context, don't know if need this yet */
	push {R4-R11}
	
	ldr r0, =tasklisthead	// pointer to tasklist
	ldr r0, [r0]		// first member of tasklist (which is still a pointer)
	// ldr r0, [r0]		// dereference to actual stack top
	msr psp, r0

	/* force EXC_RETURN: thread mode, use PSP */
    	orr lr, lr, 0x0D
	bx lr

/* literal pool */
	.balign 4
.svcall_literal_pool:
	.ltorg

