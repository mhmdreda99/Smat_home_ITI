/*
 * mcal_dio.h
 *
 *  Created on: ??�/??�/????
 *      Author: m
 */

#ifndef MCAL_DIO_PRIVATE_H_
#define MCAL_DIO_PRIVATE_H_
#endif /* MCAL_DIO_PRIVATE_H_ */


/************include section************/



/************Macro section************/




/************Macro Function section************/
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)   		 CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
//#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)    (b7 << 7 | b6 << 6 | b5 << 5 | b4 << 4 | b3 << 3 | b2 << 2 | b1 << 1 | b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)        0b##b7##b6##b5##b4##b3##b2##b1##b0
#define PORTA_DIR        CONC(PORTA_PIN7_DIRIC,PORTA_PIN6_DIRIC,PORTA_PIN5_DIRIC,PORTA_PIN4_DIRIC,PORTA_PIN3_DIRIC,PORTA_PIN2_DIRIC,PORTA_PIN1_DIRIC,PORTA_PIN0_DIRIC)
#define PORTB_DIR        CONC(PORTB_PIN7_DIRIC,PORTB_PIN6_DIRIC,PORTB_PIN5_DIRIC,PORTB_PIN4_DIRIC,PORTB_PIN3_DIRIC,PORTB_PIN2_DIRIC,PORTB_PIN1_DIRIC,PORTB_PIN0_DIRIC)
#define PORTC_DIR        CONC(PORTC_PIN7_DIRIC,PORTC_PIN6_DIRIC,PORTC_PIN5_DIRIC,PORTC_PIN4_DIRIC,PORTC_PIN3_DIRIC,PORTC_PIN2_DIRIC,PORTC_PIN1_DIRIC,PORTC_PIN0_DIRIC)
#define PORTD_DIR        CONC(PORTD_PIN7_DIRIC,PORTD_PIN6_DIRIC,PORTD_PIN5_DIRIC,PORTD_PIN4_DIRIC,PORTD_PIN3_DIRIC,PORTD_PIN2_DIRIC,PORTD_PIN1_DIRIC,PORTD_PIN0_DIRIC)

/************************logic level ************************/

#define PORTA_LOGIC       CONC(PORTA_PIN7_LOGIC,PORTA_PIN6_LOGIC,PORTA_PIN5_LOGIC,PORTA_PIN4_LOGIC,PORTA_PIN3_LOGIC,PORTA_PIN2_LOGIC,PORTA_PIN1_LOGIC,PORTA_PIN0_LOGIC)
#define PORTB_LOGIC       CONC(PORTB_PIN7_LOGIC,PORTB_PIN6_LOGIC,PORTB_PIN5_LOGIC,PORTB_PIN4_LOGIC,PORTB_PIN3_LOGIC,PORTB_PIN2_LOGIC,PORTB_PIN1_LOGIC,PORTB_PIN0_LOGIC)
#define PORTC_LOGIC        CONC(PORTC_PIN7_LOGIC,PORTC_PIN6_LOGIC,PORTC_PIN5_LOGIC,PORTC_PIN4_LOGIC,PORTC_PIN3_LOGIC,PORTC_PIN2_LOGIC,PORTC_PIN1_LOGIC,PORTC_PIN0_LOGIC)
#define PORTD_LOGIC        CONC(PORTD_PIN7_LOGIC,PORTD_PIN6_LOGIC,PORTD_PIN5_LOGIC,PORTD_PIN4_LOGIC,PORTD_PIN3_LOGIC,PORTD_PIN2_LOGIC,PORTD_PIN1_LOGIC,PORTD_PIN0_LOGIC)
/************Data type section************/


/************Function Declaration section************/