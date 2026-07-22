/**
 * @file    : hal.c
 * @brief   : hal driver
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "hal.h"
#include "hal_rcc.h"

void early_init()
{
	rcc_after_reset();
	rcc_init_hsi();
	return;
}
