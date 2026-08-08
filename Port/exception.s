.syntax unified

.global SVCall_Handler
.type SVCall_Handler, %function
SVCall_Handler:
	/* Save kernel context, don't know if need this yet */
	// push {R4-R11}
	
	ldr r0, =tasklisthead	// pointer to tasklist 
	ldr r0, [r0]		// dereference pointer to tasklist (which is still a pointer) 
	ldr r0, [r0, 0x08]	// current stack pointer is the third member of tasklist
	add r0, 0x20		// 8 * 4 = 32 = 0x20
	msr psp, r0

	/* force EXC_RETURN: thread mode, use PSP */
    	orr lr, lr, 0x0D
	bx lr

/* literal pool */
	.balign 4
.svcall_literal_pool:
	.ltorg

.section .text.exceptions
.global PendSV_Handler
.type PendSV_Handler, %function
/* When PendSV is servered, we are always in the state of tail-chaining
 * Which is: SysTick_Handler load EXEC_RETURN to PC, the core check for pending
 * Exception, and if there is no other higher priority exception preempting, PendSV
 * get serverd. The state of PendSV now is:
 * - We are in Handler mode, using MSP as stack pointer
 * - Context before SysTick is save to task PSP
 * to save task context, we can not use push instruction. Instead, we must manually get
 * the PSP from task, save r4-r11 to that pointer, using write operation to address.
 * Then calling scheduler scheme to pick next task, which update tasklistcurrent pointer.
 * Then do the same as SVCall_Handler, load this new stack to PSP, but before running 
 * EXEC_RETURN, we need to now, pop r4-r11 from the stack first. 
 * Which is now raising a problem to task initialization. We must init_context with R4-R11 for all
 * Task, but the first task to be run by SVCall_Handler.
 **/
PendSV_Handler:
	bx lr

