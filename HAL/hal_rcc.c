/**
 * @file    : hal_rcc.c
 * @brief   : RCC handler
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include <stdint.h>
#include "hal_def.h"
#include "hal_memory.h"
#include "hal_rcc.h"

/* Set of registers of RCC */
struct RCC_STRCT {
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	/* AHB peripherals reset */
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	uint32_t _reserved_0[1];
	/* APB peripherals reset */
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	uint32_t _reserved_1[2];
	/* AHB peripheral clock enable */
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	uint32_t _reserved_2[1];
	/* APB peripheral clock enable */
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	uint32_t _reserved_3[2];
	/* AHB peripheral clock enable in low power mode */
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	uint32_t _reserved_4[1];
	/* APB peripheral clock enable in low power mode */
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	uint32_t _reserved_5[2];

	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	uint32_t _reserved_6[2];
	volatile uint32_t SSCGR;	// spread spectrum clock generation register
	volatile uint32_t PLLI2SCFGR;
};

#define RCC 			((volatile struct RCC_STRCT *)RCC_BASE)
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

/* Clock configuration Register */
#define RCC_SW_HSI		(RCC_REG_MSK & (0x00 << 0))
#define RCC_SW_HSE		(RCC_REG_MSK & (0x01 << 0))
#define RCC_SW_PLL		(RCC_REG_MSK & (0x10 << 0))
// Read-only pair, compare with the set pair to see if the system has switch
#define RCC_SWS			(RCC_REG_MSK & (0x11 << 2))


/* read reset status later */
void rcc_after_reset()
{
	/* Clear reset flags, this register is no-wait state */
	RCC->CSR |= RCC_REMOVE_RESET;
}

void rcc_init_hsi()
{
	/* Access: no wait state, word, half-word and byte access */
	RCC->CR |= RCC_CR_HSION;

	/* hold for ready status */
#ifdef QEMU_BUILD
#else
	int time = 10000;
	while(((RCC->CR & RCC_CR_HSIRDY) == 0)) {
		time--;
		/* leave unhandle time out for now */
		if (time <= 0)
			break;
	}
	return;
#endif
	/* switch system clock */
	RCC->CFGR |= RCC_SW_HSI;

	/* maybe change to wait for the status == set to continue instead of a loop */
	// insert wait state
	for(int i = 10;i > 0;i--);
	if (((RCC->CFGR & RCC_SWS) >> 2) == RCC_SW_HSI)
		return;
	// Unhandled here, handler latter
	return;
}

