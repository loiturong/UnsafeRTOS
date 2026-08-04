/**
 * @file    : stm32f411xe.h
 * @brief   : Device header for F411, the file is named the same as CubeMX generated driver
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef STM32F411XE_H
#define STM32F411XE_H

/* minimal CMSIS needs */
#define __CM4_REV		0x0001U
#define __FPU_PRESENT		1U
#define __MPU_PRESENT		1U
#define __VTOR_PRESENT		1U	// CubeMX does not have this, so just put it here for latter
#define __NVIC_PRIO_BITS	4U
#define __Vendor_SysTickConfig	1U	// Use custom systick for RTOS

typedef enum
{
	NonMaskableInt_IRQn		= -14,
	MemoryManagement_IRQn		= -12,
	BusFault_IRQn			= -11,
	UsageFault_IRQn			= -10,
	SVCall_IRQn			= -5,
	DebugMonitor_IRQn		= -4,
	PendSV_IRQn			= -2,
	SysTick_IRQn			= -1,
	
	WWDG_IRQn			= 0,
	EXTI16_IRQn			= 1,
	EXTI21_IRQn			= 2,
	EXTI22_IRQn			= 3,
	FLASH_IRQn			= 4,
	RCC_IRQn			= 5,
	EXTI0_IRQn			= 6,
	EXTI1_IRQn			= 7,
	EXTI2_IRQn			= 8,
	EXTI3_IRQn			= 9,
	EXTI4_IRQn			= 10,
	DMA1_Stream0_IRQn		= 11,
	DMA1_Stream1_IRQn		= 12,
	DMA1_Stream2_IRQn		= 13,
	DMA1_Stream3_IRQn		= 14,
	DMA1_Stream4_IRQn		= 15,
	DMA1_Stream5_IRQn		= 16,
	DMA1_Stream6_IRQn		= 17,
	ADC_IRQn			= 18,

	EXTI9_5_IRQn			= 23,
	TIM1_BRK_TIM9_IRQn		= 24,
	TIM1_UP_TIM10_IRQn		= 25,
	TIM1_TRG_COM_TIM11_IRQn		= 26,
	TIM1_CC_IRQn			= 27,
	ITM2_IRQn			= 28,
	ITM3_IRQn			= 29,
	ITM4_IRQn			= 30,
	I2C1_EV_IRQn			= 31,
	I2C1_ER_IRQn			= 32,
	I2C2_EV_IRQn			= 33,
	I2C2_ER_IRQn			= 34,
	SPI1_IRQn			= 35,
	SPI2_IRQn			= 36,
	USART1_IRQn			= 37,
	USART2_IRQn			= 38,
	
	EXTI5_10_IRQn			= 40,
	EXTI17_IRQn			= 41,
	EXTI18_IRQn			= 41,

	DMA1_Stream7_IRQn		= 47,

	SDIO_IRQn			= 49,
	TIM5_IRQn			= 50,
	SPI3_IRQn			= 51,
	
	DMA2_Stream0_IRQn		= 56,
	DMA2_Stream1_IRQn		= 57,
	DMA2_Stream2_IRQn		= 58,
	DMA2_Stream3_IRQn		= 59,
	DMA2_Stream4_IRQn		= 60,

	OTG_FS_IRQn			= 67,
	DMA2_Stream5_IRQn		= 68,
	DMA2_Stream6_IRQn		= 69,
	DMA2_Stream7_IRQn		= 70,
	
	USART6_IRQn			= 71,
	I2C3_EV_IRQn			= 72,
	I2C3_ER_IRQn			= 73,

	FPU_IRQn			= 81,
	SPI4_IRQn			= 84,
	SPI5_IRQn			= 85,

} IRQn_Type;

#include "core_cm4.h"

#endif /* STM32F4111XE_H */
