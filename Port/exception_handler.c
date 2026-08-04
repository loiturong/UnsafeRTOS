/**
 * @file    : exception_handler.c
 * @brief   : exception, interrupt handler
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include <stdint.h>

uint32_t counter = 0;
void SysTick_Handler(void);
void SVCall_Handler(void);
void PendSV_Handler(void);

void SysTick_Handler(void)
{
	counter++;
}

