/**
 * @file    : interrupt.c
 * @brief   : configure interrupt
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */


#include <stdint.h>

#define SCB_ICSR		((uintptr_t *)0xE000ED04)
#define SCB_ICSR_PENDSVSET_Msk	(1 << 28)

void SysTick_Handler(void);
extern int picknewtask(void);
void SysTick_Handler(void)
{
	// PendSV may be preempt by external interrupt
	if ((*SCB_ICSR & SCB_ICSR_PENDSVSET_Msk) != 0)
		return;
	if (picknewtask())
		*SCB_ICSR |= SCB_ICSR_PENDSVSET_Msk;
	return;
}

