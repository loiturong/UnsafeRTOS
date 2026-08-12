/**
 * @file    : port.c
 * @brief   : ARM specific
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "port.h"

//	/*
//	 * SysTick configuration
//	 * Now assume using HSI
//	 * interval in miliseconnd
//	 * Entry this function require exception to be fully setup
//	 */
//	uint32_t SysTick_Config(uint32_t freq, uint32_t interval)
//	{	
//		uint32_t ticks = ((freq - 1) * interval) / 1000;
//		// Only has [23:0] usable, [32:24] is reserved
//		if (ticks > SysTick_LOAD_RELOAD_Msk)
//		{
//		  return 1;
//		}
//	
//		SysTick->LOAD = ticks;
//		SysTick->VAL = 0;
//		
//		/* CMSIS provide SetPriority Function that handle both 
//		 * External Interrupt and Core Fault Exception. 
//		 * System handler priotity registers, include a set of 3 register.
//		 * Choosing of SHPR is also handled by the function.
//		 * A PRI_N field is 8-bit wise, but F4 families implement bits[7:3] only,
//		 * so putting a 4-bit value is enough.
//		 */
//		__NVIC_SetPriority(SysTick_IRQn, 0xFFUL);
//	
//		// internal clock source + enable interrupt + enable counter
//		SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
//			SysTick_CTRL_TICKINT_Msk |
//			SysTick_CTRL_ENABLE_Msk;
//		return 0;
//	}

inline __attribute__((always_inline))
void sys_call()
{
	__asm volatile("svc 0\n");
}
