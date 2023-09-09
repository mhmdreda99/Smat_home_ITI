/*
 * MCAL_WDT_INT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_MCAL_WDT_MCAL_WDT_INT_H_
#define MCAL_MCAL_WDT_MCAL_WDT_INT_H_

#define WDT_3v_17_1ms_5v_16_3ms   0x00
#define WDT_3v_34_3ms_5v_32_5ms   0x01
#define WDT_3v_68_5ms_5v_65ms   0x02
#define WDT_3v_0_14s_5v_0_13s   0x03
#define WDT_3v_0_27s_5v_0_26s   0x04
#define WDT_3v_0_55s_5v_0_52s   0x05
#define WDT_3v_1_1s_5v_1s        0x06
#define WDT_3v_2_2s_5v_2_1s     0x07


#define Watch_Dog_Enable()   		 SET_BIT(WDTCR,WDTCR_WDE)
 //disable wdt
/*1. In the same operation, write a logic one to WDTOE and WDE. A logic one must
be written to WDE even though it is set to one before the disable operation starts.
2. Within the next four clock cycles, write a logic 0 to WDE. This disables the
Watchdog.*/

#define WDT_DISABLE_STEP_1()          SET_BIT(WDTCR,WDTCR_WDTOE)
#define WDT_DISABLE_STEP_2()          SET_BIT(WDTCR,WDTCR_WDE)
#define WDT_DISABLE_STEP_3()          CLEAR_BIT(WDTCR,WDTCR_WDE)


#define WDT_SET_TIME(_VAL)            WDTCR=((WDTCR&0xF8)|(_VAL))

   void MWDT_DISABLE(void);


	void MWDT_Start(u8 time);

#endif /* MCAL_MCAL_WDT_MCAL_WDT_INT_H_ */
