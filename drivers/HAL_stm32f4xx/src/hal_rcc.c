/**
 * @file    : hal_rcc.c
 * @brief   : RCC handler
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "hal_rcc.h"

/* read reset status later */
void rcc_after_reset()
{
	/* Clear reset flags, this register is no-wait state */
	RCC->cr_reg |= RCC_REMOVE_RESET;
}

void rcc_init_hsi()
{
	/* Access: no wait state, word, half-word and byte access */
	RCC->cr_reg |= RCC_CR_HSION;

	/* hold for ready status */
#ifdef QEMU_BUILD
	return;
#else
	int time = 10000;
	while(((RCC->cr_reg & RCC_CR_HSIRDY) == 0)) {
		time--;
		/* leave unhandle time out for now */
		if (time <= 0)
			break;
	}
	return;
#endif
}

