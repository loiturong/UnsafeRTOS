.syntax unified

.section .bootloader
.type  Reset_Handler, %function
.global Reset_Handler

Reset_Handler:
	ldr sp, =_sstack_top

	/* zero bss and copy data */
	bl init_data

	bl kernel_main
/* literal pool */
	.balign 4
.main_literal_pool:
	.ltorg

/*
 * Zero-out bss section
 */
init_data:
	push {r4, r5, r6, r7}

/* Zero out bss region on RAM */
.bss_zero:
	ldr r4, =bss_load_start
	ldr r5, =bss_size
	cmp r5, 0x00
	beq .data_copy
	mov r6, 0x00
	mov r7, 0x00
.bss_loop:
	/* str store a word = 4 bytes */
	str r7, [r4, r6]
	add r6, 0x04
	cmp r5, r6
	bpl .bss_loop

/* Copy data region to RAM */
.data_copy:
	ldr r4, =data_load_start
	ldr r5, =data_start
	ldr r6, =data_size
	cmp r6, 0x00
	beq .ret
	mov r7, 0x00
.data_loop:
	/* str store a word = 4 bytes */
	ldr r8, [r4, r7]
	str r8, [r5, r7]
	add r7, 0x04
	cmp r6, r7
	bpl .data_loop

.ret:
	pop {r4, r5, r6, r7}
	mov pc, lr
	
/* literal pool */
	.balign 4
.data_bss_literal_pool:
	.ltorg

