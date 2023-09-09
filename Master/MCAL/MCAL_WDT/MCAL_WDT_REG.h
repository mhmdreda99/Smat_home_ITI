/*
 * MCAL_WDT_REG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_MCAL_WDT_MCAL_WDT_REG_H_
#define MCAL_MCAL_WDT_MCAL_WDT_REG_H_
#define WDTCR     *((volatile u8*)(0x41))
//• Bit 4 – WDTOE: Watchdog Turn-off Enable
#define WDTCR_WDTOE   4
//• Bit 3 – WDE: Watchdog Enable
#define WDTCR_WDE     3
//how to disable

//• Bits 2..0 – WDP2, WDP1, WDP0: Watchdog Timer Prescaler 2, 1, and 0

#define WDTCR_WDP0     0
#define WDTCR_WDP1     1
#define WDTCR_WDP2     2

#endif /* MCAL_MCAL_WDT_MCAL_WDT_REG_H_ */
