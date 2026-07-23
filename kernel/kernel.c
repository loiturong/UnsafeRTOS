/**
 * @file    : kernel.c
 * @brief   : kernel entry
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include <CMSIS/DeviceHeader/stm32f405xx.h>
#include <drivers/HAL_stm32f4xx/include/hal.h>

void kernel_main()
{
	early_init();
	while(1);
}
