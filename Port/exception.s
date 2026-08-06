.syntax unified

.section .text.exceptions
.global PendSV_Handler
.type PendSV_Handler, %function
PendSV_Handler:
	bx lr

.global SVCall_Handler
.type SVCall_Handler, %function
SVCall_Handler:
	bx lr 
