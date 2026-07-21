.syntax unified

.section .bootloader
.type  reset_handler, %function
.global reset_handler

reset_handler:
	ldr sp, =_sstack_start
	bl kernel_main

.section .hardware_startup, "aw"
.type  int_table, %function
.global int_table

/* ARM fetch first 2 word for its hardware startup sequence */
.startup_seq:
	.word _sstack_start
/* also place the interrupt vector table in this region */
.int_table:
	.word reset_handler
	/* Other added latter */
	.skip 4 * (256 - 1)
