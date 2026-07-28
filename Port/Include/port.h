/**
 * @file    : port.h
 * @brief   : 
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef PORT_H
#define PORT_H

#include <stdint.h>

uint32_t SysTick_Config(uint32_t freq, uint32_t interval);
void setupNVIC(void);

#endif /* PORT_H */
