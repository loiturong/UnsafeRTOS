/**
 * @file    : interrupt.c
 * @brief   : configure interrupt
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "port.h"

void SysTick_Handler(void);
// static void setupEXTI(void);
// static inline uint32_t valid_offset(uintptr_t offset);

//	void enable_int()
//	{
//		__enable_irq();
//	}
//	
//	void disable_int()
//	{
//		__disable_irq();
//	}

//	extern char vtor_offset[];
//	void setupException()
//	{	
//		__disable_fault_irq();
//		/* VTOR offset */
//		uintptr_t offs = (uintptr_t)vtor_offset;
//		if (valid_offset(offs) != 0)
//			/* TODO: Need good way to panic here */
//			while(1);
//		SCB->VTOR = offs & SCB_VTOR_TBLOFF_Msk;
//		
//		/* System Handler */
//		__NVIC_SetPriority(MemoryManagement_IRQn, 0x00UL);
//		__NVIC_SetPriority(BusFault_IRQn, 0x01UL);
//		__NVIC_SetPriority(UsageFault_IRQn, 0x02UL);
//		__NVIC_SetPriority(DebugMonitor_IRQn, 0x03UL);
//		/* System Call, and PendSV for context switch should have lowest priority */
//		__NVIC_SetPriority(SVCall_IRQn, 0x04UL);
//		__NVIC_SetPriority(PendSV_IRQn, 0xFFUL);
//		/* Enable System Fault */
//		SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk |
//			SCB_SHCSR_BUSFAULTENA_Msk |
//			SCB_SHCSR_MEMFAULTENA_Msk;
//		setupEXTI();
//	
//		__enable_fault_irq();
//	}
//	
//	
//	uint32_t valid_offset(uintptr_t offset)
//	{
//		/* check for masking bit */
//		if (offset != (offset & SCB_VTOR_TBLOFF_Msk))
//			return -1;
//		/* Max support offset */
//		SCB->VTOR |= SCB_VTOR_TBLOFF_Msk;
//		if (offset > (SCB->VTOR & SCB_VTOR_TBLOFF_Msk))
//			return -1;
//		return 0;
//	}
//	
//	/* All External Interrupt should have priotiy below DebugMonitor */
//	static void setupEXTI()
//	{
//		/* Read maximum support interrup line register */
//		int num_lines = (32 + 32 * (int)(SCnSCB->ICTR & SCnSCB_ICTR_INTLINESNUM_Msk));
//		
//		for (int i = 0; i < num_lines; i++) {
//			__NVIC_SetPriority((IRQn_Type)i, 0xFEUL);
//			__NVIC_ClearPendingIRQ((IRQn_Type)i);
//		}
//		return;
//	}

extern int picknewtask(void);
void SysTick_Handler(void)
{
	/*
	if (picknewtask())
		SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
		*/
	return;
}

