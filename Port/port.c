/**
 * @file    : port.c
 * @brief   : ARM specific
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "stm32f405xx.h"
#include "port.h"

/*
 * SysTick configuration
 * Now assume using HSI
 * interval in miliseconnd
 */
uint32_t SysTick_Config(uint32_t freq, uint32_t interval)
{	
	uint32_t ticks = (freq - 1) / interval;
	// Only has [23:0] usable, [32:24] is reserved
	if ((ticks - 1) > SysTick_LOAD_RELOAD_Msk)
	{
	  return 1;
	}

	SysTick->LOAD = ticks;
	SysTick->VAL = 0;
	
	// internal clock source + enable interrupt + enable counter
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
		SysTick_CTRL_TICKINT_Msk |
		SysTick_CTRL_ENABLE_Msk;
	return 0;
}

