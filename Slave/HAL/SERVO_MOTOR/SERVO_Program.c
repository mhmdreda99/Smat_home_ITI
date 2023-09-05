
/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "SERVO_Interface.h"
#include "SERVO_Private.h"
#include "SERVO_Config.h"

/* Include Header Files From MCAL Layer */
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIM/TIM_interface.h"

/*==============================================================================================*/
/************************  SERVO MOTOR Functions Implementation     *******************/
/*==============================================================================================*/
/****************************     SERVO_voidRotateSpecificAngle_OC1A    *************************/
/****************************     SERVO_voidRotateSpecificAngle_OC1B    *************************/
/*==============================================================================================*/


/************************************************************************************************/
/* Function Name : SERVO_voidRotateSpecificAngle_OC1A                                           */
/* Description : Rotate Servo Motor with Specific Angle by PWM TIMER1 at PIN  OCA1   (PD5)      */                                         
/* Fun. Argument1:  Copy_u16Angle      Angle From [ 0  To  180 ] Degree                         */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SERVO_voidRotateSpecificAngle_OC1A ( u16 Copy_u16Angle )
{
    MDIO_voidSetPinDirection(PORTD,PIN5,OUTPUT);
    u32 Local_u32Variable ;

    Local_u32Variable = ((Copy_u16Angle*1000UL)+179820) / (180) ;
    MTIMERS_voidTimer1SetCompareMatchValue(Local_u32Variable);

	MTIMERS_voidTimer1SetTopValue(19999);
}

