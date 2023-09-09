/**
 * @file HAL_EEPROM_INT.c
 * @author Kareem Zidan/mhmdreda99 
 * @brief This C source code file provides functions for interfacing with an EEPROM
 * @version 0.1
 * @date 2023-09-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef HAL_EXT_EEPROM_HAL_EEPROM_INT_C_
#define HAL_EXT_EEPROM_HAL_EEPROM_INT_C_

#include"../../MCAL/std_types.h"
#include"../../MCAL/Std_Library.h"
#include "../../MCAL/macros.h"
#include"../../MCAL/I2C/MCAL_I2C_REG.h"
#include"../../MCAL/I2C/MCAL_I2C_INT.h"
#include"HAL_EEPROM_INT.h"



void HEEPROM_WRITE(u8 data,u8 address)
{
 I2C_START();
 /*slave address with write*/

 I2C_WRITE(0xA0);
 /*send memory LOCATION*/

 I2C_WRITE(address);

 I2C_WRITE(data);

 I2C_STOP();
}
/**************************************/
void HEEPROM_WRITE_STRING(u8 *user,u8 user_length,u8 s_address)
{
 int i=0;
  for(i=0;i<user_length;i++)
  {
	  HEEPROM_WRITE(user[i]-'0',s_address++);
	  _delay_ms(100);
  }

}
/**************************************/
void HEEPROM_READ_STRING(u8 *user,u8 user_length,u8 s_address)
{
 int i=0;
  for(i=0;i<user_length;i++)
  {
	  HEEPROM_READ(s_address+i,&user[i]);
  }

}
/*************************************/
void HEEPROM_READ(u8 Address,u8 *data)
{
	 I2C_START();
	 /*slave address with write*/
	 I2C_WRITE(0xA0);
	 /*send memory LOCATION*/
	 I2C_WRITE(Address);
	 I2C_START();
	 /*slave address with Read*/
	 I2C_WRITE(0xA1);
	 /*master read*/
	 *data=I2C_READ_WITH_ACK();
	 I2C_STOP();

}


#endif /* HAL_EXT_EEPROM_HAL_EEPROM_INT_C_ */
