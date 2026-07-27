/**
 * @file    : kernel.c
 * @brief   : kernel entry
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include <Port/Include/port.h>
#include <HAL/Include/hal.h>

void kernel_main()
{
	early_init();
	while(1);
}
