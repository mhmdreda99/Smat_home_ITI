
#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H


#define 	COUNTER_CLK_WISE	0
#define 	CLK_WISE			1

void HSTEPPER_voidRotate(u8 Copy_u8Direction, u16 Copy_u16Angle);

void HSTEPPER_VoidStopMotor();

#endif
