/**
 * @file EEPROM_interface.h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void HEEPROM_voidWriteData( u16 Copy_u16Location , u8 Copy_u8Data )  ;
void HEEPROM_voidReadData (u16 Copy_u16Location , u8 *Copy_pu8ReceivedData ) ;


#endif