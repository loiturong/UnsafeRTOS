/**
 * @file    : rcc.c
 * @brief   : RCC handler
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "stm32_rcc.h"

/* read reset status later */
void rcc_after_reset()
{
	/* Clear reset flags, this register is no-wait state */
	reg_set_bits(RCC->clck_stats, RCC_REMOVE_RESET);
}

void rcc_init_hsi()
{
	/* Access: no wait state, word, half-word and byte access */
	reg_set_bits(RCC->cr_reg, RCC_CR_HSION);
	
	/* hold for ready status */
	while(!(reg_get_bits(RCC->cr_reg, RCC_CR_HSIRDY)));
	return;
}

