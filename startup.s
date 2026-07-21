.syntax unified

.section .bootloader
.type  reset_handler, %function
.global reset_handler

reset_handler:
	ldr sp, =_sstack_top

	/* zero bss and copy data */
	bl zero_bss

	bl kernel_main
.main_literal_pool:
	/* literal pool */
	.ltorg

/*
 * Zero-out bss section
 */
zero_bss:
	push {r4, r5, r6, r7}
	
	ldr r4, =bss_load_start
	ldr r5, =bss_size
	cmp r5, 0x00
	beq .bss_ret

	mov r6, 0x00
	mov r7, 0x00
.bss_loop:
	/* str store a word = 4 bytes */
	str r7, [r4, r6]
	add r6, 0x04
	cmp r5, r6
	bpl .bss_loop
.bss_ret:
	pop {r4, r5, r6, r7}
	mov pc, lr
.bss_literal_pool:
	/* literal pool */
	.ltorg

.section .hardware_startup
.type  int_table, %object
.global int_table

/* ARM fetch first 2 word for its hardware startup sequence */
.startup_seq:
	.word _sstack_top
/* also place the interrupt vector table in this region */
.int_table:
	.word reset_handler
	/* Other added latter */
	.rept 255
	.word reset_handler
	.endr
