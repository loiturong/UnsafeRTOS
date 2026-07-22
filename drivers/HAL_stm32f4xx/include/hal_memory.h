/**
 * @file    : hal_memory.h
 * @brief   : memory layout
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef HAL_MEMORY_H
#define HAL_MEMORY_H

/* APB1 BUS address */
#define APB1_BASE	0x40000000

/* APB2 BUS address */
#define APB2_BASE	0x40010000

/* AHB1 BUS address */
#define AHB1_BASE	0x40020000

#define RCC_BASE	(AHB1_BASE + 0x00003800)

#endif /* HAL_MEMORY_H */
