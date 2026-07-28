/**
 * @file    : interrupt.c
 * @brief   : configure interrupt
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include <stdint.h>
#include "stm32f405xx.h"
#include "interrupt.h"

static inline uint32_t max_offs()
{
	SCB->VTOR |= SCB_VTOR_TBLOFF_Msk;

	return SCB->VTOR;
}


