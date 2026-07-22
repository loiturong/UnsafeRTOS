/**
 * @file    : hal_rcc.h
 * @brief   : clock control
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef HAL-RCC_H
#define HAL_RCC_H

#include <stdint.h>

/* Set of registers of RCC */
struct RCC_REGS {
	volatile uint32_t cr_reg;
	volatile uint32_t pll_cfg;
	volatile uint32_t clck_cfg;
	volatile uint32_t clck_int;
	/* AHB peripherals reset */
	volatile uint32_t ahb1_rs;
	volatile uint32_t ahb2_rs;
	volatile uint32_t ahb3_rs;
	/* APB peripherals reset */
	volatile uint32_t apb1_rs;
	volatile uint32_t apb2_rs;
	/* AHB peripheral clock enable */
	volatile uint32_t ahb1_ena;
	volatile uint32_t ahb2_ena;
	volatile uint32_t ahb3_ena;
	/* APB peripheral clock enable */
	volatile uint32_t apb1_ena;
	volatile uint32_t apb2_ena;
	/* AHB peripheral clock enable in low power mode */
	volatile uint32_t ahb1_ena_lpw;
	volatile uint32_t ahb2_ena_lpw;
	volatile uint32_t ahb3_ena_lpw;
	/* APB peripheral clock enable in low power mode */
	volatile uint32_t apb1_ena_lpw;
	volatile uint32_t apb2_ena_lpw;

	volatile uint32_t backup_cr;
	volatile uint32_t clck_stats;
	/* spread spectrum clock generation register */
	volatile uint32_t spd_spctum_clck_gen;

	volatile uint32_t plli2s_cfg;
};

#define RCC 			((volatile struct RCC_REGS *)RCC_BASE)
#define RCC_REG_MSK		0xFFFFFFFFU

/* Clock Control Register */

#define RCC_CR_HSION		(RCC_REG_MSK & (1 << 0))
#define RCC_CR_HSIRDY		(RCC_REG_MSK & (1 << 1))
#define RCC_CR_HSITRIM		(RCC_REG_MSK & (0x1F << 3))
#define RCC_CR_HSICAL		(RCC_REG_MSK & (0xFF << 8))

#define RCC_CR_HSEON		(RCC_REG_MSK & (1 << 16))
#define RCC_CR_HSEEDY		(RCC_REG_MSK & (1 << 17))
#define RCC_CR_HSEBYP		(RCC_REG_MSK & (1 << 18))

#define RCC_CR_CSSON		(RCC_REG_MSK & (1 << 19))

#define RCC_CR_PLLON		(RCC_REG_MSK & (1 << 24))
#define RCC_CR_PLLRDY		(RCC_REG_MSK & (1 << 25))
#define RCC_CR_PLLI2SON		(RCC_REG_MSK & (1 << 26))
#define RCC_CR_PLLI2SRDY	(RCC_REG_MSK & (1 << 27))

/* clock control & status Register */
#define RCC_REMOVE_RESET	(RCC_REG_MSK & (1 << 24))

void rcc_after_reset();
void rcc_init_hsi();

#endif /* HAL_RCC_H */
