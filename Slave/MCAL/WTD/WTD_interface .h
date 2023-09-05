/**
 * @file WTD_interface .h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef WTD_INTERFACE_H
#define WTD_INTERFACE_H

#define     WDT_16_3_ms         0
#define     WDT_32_5_ms         1
#define     WDT_1_5             6

void        MWTD_voidEnable()                  ;
void        MWTD_voidSleep(u8 Copy_u8TimerOut) ;
void        MWTD_voidDisable()                 ;

#endif