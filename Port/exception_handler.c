/**
 * @file    : exception_handler.c
 * @brief   : exception, interrupt handler
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "stm32f411xe.h"
#include <stdint.h>

void SysTick_Handler(void);
void SVCall_Handler(void);
void PendSV_Handler(void);

void SysTick_Handler(void)
{
	// PendSV doing the context switch
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
	return;
}

void PendSV_Handler(void)
{

}

