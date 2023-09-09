/*
 * SPI_REG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_SPI_SPI_REG_H_
#define MCAL_SPI_SPI_REG_H_
/***********SPI Control Register – SPCR*************/
#define SPCR    *((volatile u8*)(0x2D))
//• Bit 7 – SPIE: SPI Interrupt Enable
#define SPCR_SPIE  7


//• Bit 6 – SPE: SPI Enable
#define SPCR_SPE 6




//• Bit 5 – DORD: Data Order
#define SPCR_DORD  5


//• Bit 4 – MSTR: Master/Slave Select
#define SPCR_MSTR   4



//CPOL BIT 3 CLOCK POLARITY
#define SPCR_CPOL  3



//• Bit 2 – CPHA: Clock Phase
//transmit -> setup
//receive -> sample
#define SPCR_CPHA  2

//• Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0

#define SPCR_SPR0 		0
#define SPCR_SPR1 		1



//SPI Status Register – SPSR
#define SPSR    *((volatile u8*)(0x2E))


//• Bit 7 – SPIF: SPI Interrupt Flag
/*
When a serial transfer is complete, the SPIF Flag is set. An interrupt is generated if
SPIE in SPCR is set and global interrupts are enabled. If SS is an input and is driven low
when the SPI is in Master mode, this will also set the SPIF Flag. SPIF is cleared by
hardware when executing the corresponding interrupt handling vector. Alternatively, the
SPIF bit is cleared by first reading the SPI Status Register with SPIF set, then accessing
the SPI Data Register (SPDR).
*/
#define SPSR_SPIF  7
//The WCOL bit is set if the SPI Data Register (SPDR) is written during a data transfer.
//The WCOL bit (and the SPIF bit) are cleared by first reading the SPI Status Register
//with WCOL set, and then accessing the SPI Data Register.
#define SPSR_WCOL 6
#define SPSR_I2X  0
//SPI Data Register – SPDR
#define SPDR  *((volatile u8*)(0x2F))

#endif /* MCAL_SPI_SPI_REG_H_ */
