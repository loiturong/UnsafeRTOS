.syntax unified
/* TODO: Adding task state indicating the use of hardware floating point in context swithcing */

.global SVCall_Handler
.type SVCall_Handler, %function
SVCall_Handler:
	/* Save kernel context, don't know if need this yet */
	// push {R4-R11}
	
	ldr r0, =g_p_first_task	// pointer to first task control block 
	ldr r0, [r0]		// dereference pointer to tasklist (which is still a pointer) 
	ldr r0, [r0]		// current stack pointer is now the first member of tasklist
	add r0, 0x20		// 8 * 4 = 32 = 0x20
	msr psp, r0

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
 * Then do the same as SVCall_Handler to switch to new task.
 */
PendSV_Handler:
	/* Save current task context */
	mrs r0, psp

	sub r0,  0x20
	str r4,  [r0, 0x20]
	str r5,  [r0, 0x1c]
	str r6,  [r0, 0x18]
	str r7,  [r0, 0x14]
	str r8,  [r0, 0x10]
	str r9,  [r0, 0x0c]
	str r10, [r0, 0x08]
	str r11, [r0, 0x04]
	
	ldr r1, =g_p_prev_task	// pointer to tasklist 
	ldr r1, [r1]		// dereference pointer to tasklist (which is still a pointer) 
	str r0, [r1]		// current stack pointer is now the first member of tasklist
	

	/* Switch to new task */
	ldr r0, =g_p_curr_task	// pointer to tasklist 
	ldr r0, [r0]		// dereference pointer to tasklist (which is still a pointer) 
	ldr r0, [r0]		// current stack pointer is now the first member of tasklist

	/* "restore" context of new task */
	ldr r11, [r0, 0x04]
	ldr r10, [r0, 0x08]
	ldr r9,  [r0, 0x0c]
	ldr r8,  [r0, 0x10]
	ldr r7,  [r0, 0x14]
	ldr r6,  [r0, 0x18]
	ldr r5,  [r0, 0x1c]
	ldr r4,  [r0, 0x20]
	add r0, 0x20
	
	msr psp, r0
	
	orr lr, lr, 0x0D
	bx lr

/* literal pool */
	.balign 4
.pendsv_literal_pool:
	.ltorg

