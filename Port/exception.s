.syntax unified

.section .text.exceptions
.global PendSV_Handler
PendSV_Handler:
	bx lr

.global SVCall_Handler
SVCall_Handler:
	bx lr 
