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
	NonMaskableInt_IRQn         = -14,
	MemoryManagement_IRQn       = -12,
	BusFault_IRQn               = -11,
	UsageFault_IRQn             = -10,
	SVCall_IRQn                 = -5,
	DebugMonitor_IRQn           = -4,
	PendSV_IRQn                 = -2,
	SysTick_IRQn                = -1,
} IRQn_Type;

#include "core_cm4.h"

#endif /* STM32F4111XE_H */
