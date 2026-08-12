/**
 * @file    : interrupt.c
 * @brief   : configure interrupt
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

void SysTick_Handler(void);

extern int picknewtask(void);
void SysTick_Handler(void)
{
	/*
	if (picknewtask())
		SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
		*/
	return;
}

