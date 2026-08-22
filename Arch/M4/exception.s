.syntax unified
/* TODO: Adding task state indicating the use of hardware floating point in context swithcing */

.section .text.exceptions

.global SVCall_Handler
.type SVCall_Handler, %function

SVCall_Handler:
	and r0, lr, 0x04
	cmp r0, 0x04
	bne get_msp_arg

// Load Stack
	mrs r1, psp
	b exec
get_msp_arg:
	mrs r1, msp

exec:
	ldr r1, [r1, 0x18]	// PC after svc call
	sub r1, 0x02
	ldrh r1, [r1]		// the SVC instruction
	and r1, r1, 0xFF	// syscall number

	ldr r0, =syscall_table
	lsl r1, r1, 0x02
	ldr r0, [r0, r1]
	
	push {lr}
	blx r0
	pop {lr}
	bx lr

/* literal pool */
	.balign 4
.literal_pool_svcall:
	.ltorg

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
	
	ldr r2, =g_p_task_current	// pointer to node_t current task pointer

	ldr r1, [r2]			// node_t
	str r0, [r1]			// store node_t->tcb (first member is already stack pointer)
	
	/* Update current task pointer */
	ldr r1, [r2]			// node_t
	ldr r0, [r1, 0x0C]		// node_t->next (node_t)
	str r0, [r2]

	/* Switch to new task */
	ldr r1, [r2]			// node_t
	ldr r0, [r1]			// node_t->p_tcb (stack is the first member)

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
.literal_pool_pendsv:
	.ltorg

