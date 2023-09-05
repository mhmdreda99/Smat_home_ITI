

/* File Gaurd by ifndef & endif */
#ifndef SERVO_INTERFACE_H
#define SERVO_INTERFACE_H


/*==============================================================================================*/
/**************************    A.BAHAA SERVO MOTOR Functions Prototypes     *********************/
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
void SERVO_voidRotateSpecificAngle_OC1A ( u16 Copy_u16Angle );




#endif
