.syntax unified

.section .bootloader
.type  reset_handler, %function
.global reset_handler

reset_handler:
	ldr sp, =_sstack_top
	bl kernel_main

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
	.skip 4 * (256 - 1)
