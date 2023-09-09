/*
 * MCAL_WDT_INT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */
#include"../std_types.h"
#include"../macros.h"
#include"MCAL_WDT_REG.h"
#include"MCAL_WDT_INT.h"
	void MWDT_Start(u8 _VAL)
	{

		Watch_Dog_Enable();

		WDTCR=((WDTCR&0xF8)|(_VAL));
	}

	   void MWDT_DISABLE(void)
	   {

		   SET_BIT(WDTCR,WDTCR_WDTOE);
		   WDT_DISABLE_STEP_2();
		   asm("nop");
		   asm("nop");
		   asm("nop");
		   asm("nop");
		   WDT_DISABLE_STEP_3();

	   }
