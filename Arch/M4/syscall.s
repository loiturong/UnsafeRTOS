.syntax unified

.section .text.system_call
.global syscall_restore_context
.type syscall_restore_context, %function

/* Restore context from task_control_block,
 * which is store in g_p_task_current, a scheduler's node_t structure
 */
syscall_restore_context:
	
	ldr r0, =g_p_task_current	// pointer to node_t
	ldr r0, [r0]			// node_t
	ldr r0, [r0]			// node_t->p_tcb
	ldr r0, [r0]			// p_tcb->task_st
	
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
.syscall_rstcnxt_literal_pool:
	.ltorg

.section .rodata.syscall_jump_table
.global syscall_table
.type syscall_table, %object
syscall_table:
	.word syscall_restore_context
