.syntax unified

/*
 * This Interurpt vector table is based on RM0383 Reference manual for F411
 * TODO: Find some way to upgrade HAL build system to handle multiple board support (latter)
*/
.section .interrupt_vector_table, "a", %progbits
.type  external_interrupt_vector_table, %object
.global external_interrupt_vector_table

.macro  _repeat0 a=1
	.rept \a
	.word 0x00
	.endr
.endm

/* External Interrupt
 * Some Reserved Entry is set as 0x00,
 * attempt to access this entry will likely cause 
 * Usagefault as it try to run some Non-Thumb code.
 */
.external_interrupt_vector_table:
	.word WWDG_Handler
	.word EXTI16_Handler
	.word EXTI21_Handler
	.word EXTI22_Handler
	.word FLASH_INT_Handler
	.word RCC_INT_Handler
	.word EXTI0_Handler
	.word EXTI1_Handler
	.word EXTI2_Handler
	.word EXTI3_Handler
	.word EXTI4_Handler
	.word DMA1_Stream0_INT_Handler
	.word DMA1_Stream1_INT_Handler
	.word DMA1_Stream2_INT_Handler
	.word DMA1_Stream3_INT_Handler
	.word DMA1_Stream4_INT_Handler
	.word DMA1_Stream5_INT_Handler
	.word DMA1_Stream6_INT_Handler
	.word ADC_INT_Handler

	_repeat0 4

	.word EXTI9_5_INT_Handler
	.word TIM1_BRK_TIM9_INT_Handler
	.word TIM1_UP_TIM10_INT_Handler
	.word TIM1_TRG_COM_TIM11_INT_Handler
	.word TIM1_CC_INT_Handler
	.word ITM2_INT_Handler
	.word ITM3_INT_Handler
	.word ITM4_INT_Handler
	.word I2C1_EV_INT_Handler
	.word I2C1_ER_INT_Handler
	.word I2C2_EV_INT_Handler
	.word I2C2_ER_INT_Handler
	.word SPI1_INT_Handler
	.word SPI2_INT_Handler
	.word USART1_INT_Handler
	.word USART2_INT_Handler

	_repeat0 1

	.word EXTI5_10_Handler
	.word EXTI17_Handler
	.word EXTI18_Handler
	
	_repeat0 4

	.word DMA1_Stream7_INT_Handler

	_repeat0 1

	.word SDIO_INT_Handler
	.word TIM5_INT_Handler
	.word SPI3_INT_Handler

	_repeat0 4

	.word DMA2_Stream0_INT_Handler
	.word DMA2_Stream1_INT_Handler
	.word DMA2_Stream2_INT_Handler
	.word DMA2_Stream3_INT_Handler
	.word DMA2_Stream4_INT_Handler

	_repeat0 6

	.word OTG_FS_INT_Handler
	.word DMA2_Stream5_INT_Handler
	.word DMA2_Stream6_INT_Handler
	.word DMA2_Stream7_INT_Handler
	.word USART6_INT_Handler
	.word I2C3_EV_INT_Handler
	.word I2C3_ER_INT_Handler
	
	_repeat0 7

	.word FPU_INT_Handler
	
	_repeat0 2
	
	.word SPI4_INT_Handler
	.word SPI5_INT_Handler

.section .text.exceptions
/* Default interrupt handler
 * This function "branching" EXEC_RETURN value into PC register, 
 * which will cause an exception return, and pop the stack frame from which the cpu enterd.
 * TODO: replace this function with a macro that handle clear IRQ source, 
 * or handle clear IRQ source inside this function.
 */
Default_Interrupt_Handler:
	bx lr

.weak WWDG_Handler
.weak EXTI16_Handler
.weak EXTI21_Handler
.weak EXTI22_Handler
.weak FLASH_INT_Handler
.weak RCC_INT_Handler
.weak EXTI0_Handler
.weak EXTI1_Handler
.weak EXTI2_Handler
.weak EXTI3_Handler
.weak EXTI4_Handler
.weak DMA1_Stream0_INT_Handler
.weak DMA1_Stream1_INT_Handler
.weak DMA1_Stream2_INT_Handler
.weak DMA1_Stream3_INT_Handler
.weak DMA1_Stream4_INT_Handler
.weak DMA1_Stream5_INT_Handler
.weak DMA1_Stream6_INT_Handler
.weak ADC_INT_Handler
.weak EXTI9_5_INT_Handler
.weak TIM1_BRK_TIM9_INT_Handler
.weak TIM1_UP_TIM10_INT_Handler
.weak TIM1_TRG_COM_TIM11_INT_Handler
.weak TIM1_CC_INT_Handler
.weak ITM2_INT_Handler
.weak ITM3_INT_Handler
.weak ITM4_INT_Handler
.weak I2C1_EV_INT_Handler
.weak I2C1_ER_INT_Handler
.weak I2C2_EV_INT_Handler
.weak I2C2_ER_INT_Handler
.weak SPI1_INT_Handler
.weak SPI2_INT_Handler
.weak USART1_INT_Handler
.weak USART2_INT_Handler
.weak EXTI5_10_Handler
.weak EXTI17_Handler
.weak EXTI18_Handler
.weak DMA1_Stream7_INT_Handler
.weak SDIO_INT_Handler
.weak TIM5_INT_Handler
.weak SPI3_INT_Handler
.weak DMA2_Stream0_INT_Handler
.weak DMA2_Stream1_INT_Handler
.weak DMA2_Stream2_INT_Handler
.weak DMA2_Stream3_INT_Handler
.weak DMA2_Stream4_INT_Handler
.weak OTG_FS_INT_Handler
.weak DMA2_Stream5_INT_Handler
.weak DMA2_Stream6_INT_Handler
.weak DMA2_Stream7_INT_Handler
.weak USART6_INT_Handler
.weak I2C3_EV_INT_Handler
.weak I2C3_ER_INT_Handler
.weak FPU_INT_Handler
.weak SPI4_INT_Handler
.weak SPI5_INT_Handler


/* Unimplement Interrupt got linked to Default_Interrupt_Handler*/
.thumb_set WWDG_Handler, Default_Interrupt_Handler
.thumb_set EXTI16_Handler, Default_Interrupt_Handler
.thumb_set EXTI21_Handler, Default_Interrupt_Handler
.thumb_set EXTI22_Handler, Default_Interrupt_Handler
.thumb_set FLASH_INT_Handler, Default_Interrupt_Handler
.thumb_set RCC_INT_Handler, Default_Interrupt_Handler
.thumb_set EXTI0_Handler, Default_Interrupt_Handler
.thumb_set EXTI1_Handler, Default_Interrupt_Handler
.thumb_set EXTI2_Handler, Default_Interrupt_Handler
.thumb_set EXTI3_Handler, Default_Interrupt_Handler
.thumb_set EXTI4_Handler, Default_Interrupt_Handler
.thumb_set DMA1_Stream0_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA1_Stream1_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA1_Stream2_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA1_Stream3_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA1_Stream4_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA1_Stream5_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA1_Stream6_INT_Handler, Default_Interrupt_Handler
.thumb_set ADC_INT_Handler, Default_Interrupt_Handler
.thumb_set EXTI9_5_INT_Handler, Default_Interrupt_Handler
.thumb_set TIM1_BRK_TIM10_INT_Handler, Default_Interrupt_Handler
.thumb_set TIM1_UP_TIM11_INT_Handler, Default_Interrupt_Handler
.thumb_set TIM1_TRG_COM_TIM11_INT_Handler, Default_Interrupt_Handler
.thumb_set TIM1_CC_INT_Handler, Default_Interrupt_Handler
.thumb_set ITM2_INT_Handler, Default_Interrupt_Handler
.thumb_set ITM3_INT_Handler, Default_Interrupt_Handler
.thumb_set ITM4_INT_Handler, Default_Interrupt_Handler
.thumb_set I2C1_EV_INT_Handler, Default_Interrupt_Handler
.thumb_set I2C1_ER_INT_Handler, Default_Interrupt_Handler
.thumb_set I2C2_EV_INT_Handler, Default_Interrupt_Handler
.thumb_set I2C2_ER_INT_Handler, Default_Interrupt_Handler
.thumb_set SPI1_INT_Handler, Default_Interrupt_Handler
.thumb_set SPI2_INT_Handler, Default_Interrupt_Handler
.thumb_set USART1_INT_Handler, Default_Interrupt_Handler
.thumb_set USART2_INT_Handler, Default_Interrupt_Handler
.thumb_set EXTI5_10_Handler, Default_Interrupt_Handler
.thumb_set EXTI17_Handler, Default_Interrupt_Handler
.thumb_set EXTI18_Handler, Default_Interrupt_Handler
.thumb_set DMA1_Stream7_INT_Handler, Default_Interrupt_Handler
.thumb_set SDIO_INT_Handler, Default_Interrupt_Handler
.thumb_set TIM5_INT_Handler, Default_Interrupt_Handler
.thumb_set SPI3_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA2_Stream0_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA2_Stream1_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA2_Stream2_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA2_Stream3_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA2_Stream4_INT_Handler, Default_Interrupt_Handler
.thumb_set OTG_FS_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA2_Stream5_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA2_Stream6_INT_Handler, Default_Interrupt_Handler
.thumb_set DMA2_Stream7_INT_Handler, Default_Interrupt_Handler
.thumb_set USART6_INT_Handler, Default_Interrupt_Handler
.thumb_set I2C3_EV_INT_Handler, Default_Interrupt_Handler
.thumb_set I2C3_ER_INT_Handler, Default_Interrupt_Handler
.thumb_set FPU_INT_Handler, Default_Interrupt_Handler
.thumb_set SPI4_INT_Handler, Default_Interrupt_Handler
.thumb_set SPI5_INT_Handler, Default_Interrupt_Handler
