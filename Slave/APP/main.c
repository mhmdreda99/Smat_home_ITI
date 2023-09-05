/**
 s* @file main.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "main.h"

#include "../LIB/STD_TYPES.h"
#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/TIM/TIM_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"


#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/STEPPER/STEPPER_interace.h"
#include "../HAL/SERVO_MOTOR/SERVO_Interface.h"


/* Function to sum up all the drivers needed to be initiated */
void Sys_Init(void)   ;
void Sys_PinsDirection(void) ;

extern u8 MSPI_u8ReceivedData    ;
/**
 * @brief 
 * 
 * @return int 
 */
int main()
{
	Sys_Init();
	Sys_PinsDirection() ;


/****** Local Variables ********/
	volatile u16 LDR_DigitalValue  ;
	volatile u16 LM35_DigitalValue ;
	u8  Mapped_LDR		  ;
	u8  Mapped_LM35		  ;
	u8  Room_Lights = OFF ;
	u8  PIR_Reading = 0   ;
	u8  MAX_CompareValue = 255;


/*****Initial Setting System to be off ****/
	MSPI_u8ReceivedData = 12  ;

	while(1)
	{

		//Saving Sensors Readings
		LDR_DigitalValue = MADC_u16StartConversionSync(ADC_CHANNEL0) ;
		PIR_Reading      = MDIO_u8GetPinValue(PORTA,PIN2)            ;

		//Mapping Reading to PWM Values
		Mapped_LDR =MAP(0,1023,0,255,LDR_DigitalValue)  ;

		//Checking If Room light is on/off or there is no one in room or not
		if(Room_Lights==ON && PIR_Reading == 1)
		{
			MTIMERS_voidTimer0SetCompareMatchValue(MAX_CompareValue - Mapped_LDR) ;
		}
		else if(Room_Lights == OFF || PIR_Reading == 0 )
		{
			MTIMERS_voidTimer0SetCompareMatchValue(MAX_CompareValue)	;
		}

		switch(SPDR)
		{
			case TURN_LIGHT_ON:
				MDIO_voidSetPinValue(PORTA,PIN3,HIGH) ;	// Reception Light
				Room_Lights = ON ; // Room Light
				HLCD_voidClearAll() ;
				HLCD_voidSendString("Lights ON") ;
				MSPI_u8ReceivedData = DEFAULT_STATE;
				break ;
			case TURN_LIGHT_OFF:
				MDIO_voidSetPinValue(PORTA,PIN3,LOW)  ;  // Reception Light
				Room_Lights = OFF;  // Room Light
				HLCD_voidClearAll() ;
				HLCD_voidSendString("Lights OFF") ;
				MSPI_u8ReceivedData = DEFAULT_STATE ;
				break ;
			case TURN_FAN_ON :
				LM35_DigitalValue= MADC_u16StartConversionSync(ADC_CHANNEL1) ;
				Mapped_LM35=MAP(0,1023,0,255,LM35_DigitalValue)         ;
				MTIMERS_voidTimer2SetCompareMatchValue(MAX_CompareValue - Mapped_LM35) ; //(NEED ADJUSTING)
				HLCD_voidClearAll() ;
				HLCD_voidSendString("FAN ON ") ;
				MSPI_u8ReceivedData = DEFAULT_STATE ;
				break ;
			case TURN_FAN_OFF:
				LM35_DigitalValue= MADC_u16StartConversionSync(ADC_CHANNEL1) ;
				Mapped_LM35=MAP(0,1023,0,255,LM35_DigitalValue)         ;
				MTIMERS_voidTimer2SetCompareMatchValue(MAX_CompareValue) ; //(NEED ADJUSTING)
				HLCD_voidSendString("FAN OFF") ;
				HLCD_voidClearAll() ;
				MSPI_u8ReceivedData = DEFAULT_STATE ;
				break ;
			case GARAGE_ON :
				HSTEPPER_voidRotate(COUNTER_CLK_WISE, 270); // Open Curtains  (NEED ADJUSTING)
				HLCD_voidClearAll() ;
				HLCD_voidSendString("Garage Open") ;
				MSPI_u8ReceivedData = DEFAULT_STATE ;
				break;
			case GARAGE_OFF :
				HSTEPPER_voidRotate(COUNTER_CLK_WISE, 270); // Close Curtains (NEED ADJUSTING)
				HLCD_voidClearAll() ;
				HLCD_voidSendString("Garage Close") ;
				MSPI_u8ReceivedData = DEFAULT_STATE ;
				break;

			case DOOR_OPEN :
				SERVO_voidRotateSpecificAngle_OC1A (180); // door will open (Servo motor will move to angle 180)
				HLCD_voidClearAll() ;
				HLCD_voidSendString("Door opened") ;
				MSPI_u8ReceivedData = DEFAULT_STATE ;
				break;

			case DOOR_CLOSE :
				SERVO_voidRotateSpecificAngle_OC1A (0); // door will close (Servo motor will move to angle 0)
				HLCD_voidClearAll() ;
				HLCD_voidSendString("Door Closed") ;
				MSPI_u8ReceivedData = DEFAULT_STATE ;
				break;
			case SYSTEM_OFF  :
				HLCD_voidSendString("System Is OFF") ;
				while(MSPI_u8ReceivedData != SYSTEM_ON) ; // Polling Until System is on
				HLCD_voidSendString("System Is ON , Welcome") ;
				_delay_ms(2000) ;
				HLCD_voidClearAll() ;
				break ;


			case DEFAULT_STATE:
				//do nothing
				break ;
			default:
				HLCD_voidSendString("System ERROR.") ;
				HLCD_voidSendNumber (MSPI_u8ReceivedData) ;
				_delay_ms(2000) ;
				HLCD_voidClearAll() ;
				break ;
		}
	}
}
/**
 * @brief 
 * 
 */
void Sys_Init()
{
	/* Initiate ADC For Reading LDR Value & LM35 Value */
	MADC_voidInit()					;
	/* Initiate Timers Needed Timer 0 -> PWM   , Timer 1 -> SetBusyWait , Timer 2 -> DC Motor */
	MTIMERS_voidTimer0Init()		;
	MTIMERS_voidTimer1Init()		;
	MTIMERS_voidTimer2Init()		;
	/* Initiate SPI communication to communicate with the Master controller */
	MSPI_voidSlaveInit() 			;
	/* Initiate LCD Connections */
	HLCD_voidInit()      			;
}
/**
 * @brief 
 * 
 */
void Sys_PinsDirection()
{
	//PORTA
	MDIO_voidSetPinDirection(PORTA,PIN0,INPUT)  ; // For ADC channel 0 (LDR   Reading)
	MDIO_voidSetPinDirection(PORTA,PIN1,INPUT)  ; // For ADC channel 1 (LM-35 Reading)
	MDIO_voidSetPinDirection(PORTA,PIN2,INPUT)  ; // For PIR Signal
	MDIO_voidSetPinDirection(PORTA,PIN3,OUTPUT) ; // For Reception LED

	//PORTB (Pin 0,1,2 For LCD )  (Pin 4,5,6,7 For SPI)
	MDIO_voidSetPinDirection(PORTB,PIN3,OUTPUT) ; // For Timer 0 ( Room LED )
	MDIO_voidSetPinDirection(PORTB,PIN4,INPUT)  ;
	MDIO_voidSetPinDirection(PORTB,PIN5,OUTPUT) ;
	MDIO_voidSetPinDirection(PORTB,PIN6,INPUT)  ;
	MDIO_voidSetPinDirection(PORTB,PIN7,INPUT)  ;

	//PORTC (All For LCD Data)

	//PORTD (Pins 1,2,3,4 For Stepper)
	MDIO_voidSetPinDirection(PORTD,PIN7,OUTPUT) ; // For Timer 2 (DC Motor Fan )
}


