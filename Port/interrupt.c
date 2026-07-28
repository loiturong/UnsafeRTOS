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

static inline uint32_t valid_offset(uintptr_t offset)
{
	/* check for masking bit */
	if (offset != (offset & SCB_VTOR_TBLOFF_Msk))
		return -1;
	/* Max support offset */
	SCB->VTOR |= SCB_VTOR_TBLOFF_Msk;
	if (offset > (SCB->VTOR & SCB_VTOR_TBLOFF_Msk))
		return -1;
	return 0;
}

extern char vtor_offset[];
void setupNVIC()
{
	/* VTOR offset */
	uintptr_t offs = (uintptr_t)vtor_offset;
	if (valid_offset(offs) != 0)
		/* TODO: Need good way to panic here */
		while(1);
	SCB->VTOR = offs & SCB_VTOR_TBLOFF_Msk;
}
