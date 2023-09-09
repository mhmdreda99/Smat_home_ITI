/*
 * MCAL_I2C_REG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_I2C_MCAL_I2C_REG_H_
#define MCAL_I2C_MCAL_I2C_REG_H_

//TWI Bit Rate Register – TWBR
/*The bit rate generator is a
frequency divider which generates the SCL clock frequency in the Master modes. See
“Bit Rate Generator Unit” on page 173 for calculating bit rate*/
#define TWBR  *((volatile u8 *)(0x20))



#define TWCR  *((volatile u8 *)(0x56))
/*note that clearing this flag starts the operation of the TWI, so all accesses to
the TWI Address Register (TWAR), TWI Status Register (TWSR),
and TWI Data Register (TWDR) must be complete before clearing this flag.*/

//interrupt flag cleared by software (user)
#define TWCR_TWINT   7


//• Bit 6 – TWEA: TWI Enable Acknowledge Bit
#define TWCR_TWEA    6


//• Bit 5 – TWSTA: TWI START Condition Bit
#define TWCR_TWSTA  5


/*In slave mode, setting the TWSTO bit can be used to recover
from an error condition. This will not generate a STOP condition, but the TWI returns to
a well-defined un addressed slave mode and releases the SCL and SDA lines to a high
impedance state.*/
//• Bit 4 – TWSTO: TWI STOP Condition Bit
#define TWCR_TWSTO  4

//• Bit 3 – TWWC: TWI Write Collision Flag
#define TWCR_TWWC  3


//• Bit 2 – TWEN: TWI Enable Bit

#define TWCR_TWEN  2



//• Bit 0 – TWIE: TWI Interrupt Enable
#define TWCR_TWIE 0


//TWI Status Register – TWSR
#define TWSR  *((volatile u8 *)(0x21))
//why the interrupt flag is setted by this 5 bits
/****prescaler select ****/
#define TWSR_TWPS0  0
#define TWSR_TWPS1  1


/*****flag status*******/
#define TWSR_TWS3   3
#define TWSR_TWS4   4
#define TWSR_TWS5   5
#define TWSR_TWS6   6
#define TWSR_TWS7   7



//TWI Data Register – TWDR
#define TWDR  *((volatile u8 *)(0x23))

/*WI (Slave) Address Register – TWAR*/
#define TWAR  *((volatile u8 *)(0x22))

//• Bit 0 – TWGCE: TWI General Call Recognition Enable Bit
#define TWAR_TWGCE  0

//• Bits 7..1 – TWA: TWI (Slave) Address Register
//here we set the slave address

#endif /* MCAL_I2C_MCAL_I2C_REG_H_ */
