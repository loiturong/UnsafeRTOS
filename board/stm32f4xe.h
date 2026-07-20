/**
 * @file    : stm32f4xe.h
 * @brief   : Device header for F4 family
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef STM32F4XE_H
#define STM32F4XE_H

/* minimal CMSIS needs */
#define __FPU_USED		1U
#define __CM4_REV		0x0001U
#define __MPU_PRESENT		1U
#define __VTOR_PRESENT		1U	// CubeMX does not have this, so just put it here for latter
#define __NVIC_PRIO_BITS	4U
#define __Vendor_SysTickConfig	1U	// Use custom systick for RTOS

typedef enum
{
	NonMaskableInt_IRQn         = -14,
	MemoryManagement_IRQn       = -12,
	BusFault_IRQn               = -11,
	UsageFault_IRQn             = -10,
	SVCall_IRQn                 = -5,
	DebugMonitor_IRQn           = -4,
	PendSV_IRQn                 = -2,
	SysTick_IRQn                = -1,
} IRQ_TYPE;

#include <CMSIS/Include/core_cm4.h>

#endif /* STM32F4XE_H */
