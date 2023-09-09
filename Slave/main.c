/**
 * @file main.c
 * @author Kareem Zidan /mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "main.h"
#include <stdarg.h>
#include"MCAL/std_types.h"
#include"MCAL/Std_Library.h"
#include<stddef.h>
#include"MCAL/macros.h"
#include "MCAL/DIO/MCAL_DIO_REGISTERS.h"
#include "MCAL/DIO/MCAL_DIO_INTERFACE.h"
#include"MCAL/SPI/SPI_INT.h"

#include"HAL/KEYPAD/keypad_interface.h"
#include"RTOS/RTOS_INT.h"

#include "MCAL/SPI/SPI_REG.h"
#include "MCAL/Timer_0/MCAL_TIMER0_INT.h"
#include "MCAL/Timer_0/MCAL_TIMER0_REG.h"


u8 Receive_Data=0;
volatile u8 adc_flag=0;

volatile u8 tensDigit ;
volatile u8 onesDigit ;
const uint8_t sevenSegDigits[10] = {
		// a  b  c  d  e  f  g
		0x3F, // 0
		0x06, // 1
		0x5B, // 2
		0x4F, // 3
		0x66, // 4
		0x6D, // 5
		0x7D, // 6
		0x07, // 7
		0x7F, // 8
		0x6F  // 9
};
/**********FUNCTION DECLERATION*********/
/**
 * @file main.c
 * @brief Main program entry point.
 * @version 1.0
 * @date 2023-09-08
 *
 * This is the main entry point of the program. It initializes the required
 * hardware peripherals, sets up SPI communication, and continuously displays
 * data on a seven-segment display.
 *
 * @note Ensure that the necessary hardware peripherals and configurations are
 * set up properly before running this program.
 *
 * @return An integer value representing the program's exit status.
 */
int main()
{
	PORT_DIRECTION_INIT();
	PORT_LOGICLEVEL_INIT();
	MSPI_Init(READ_SPI);
	TIMER0_SETCALLBACK(MTIMER0_ISR);
	MTIMER0_VoidInit();

	while(1)
	{

		seg_display(onesDigit,tensDigit);

	}


}

/**
 * @brief Read data via SPI and perform corresponding actions.
 *
 * This function reads data from SPI (Serial Peripheral Interface) and performs
 * actions based on the received data. It handles various control commands and
 * responds accordingly.
 *
 * - If the `adc_flag` is set to 1, it reads the data and updates PORTD.
 * - If the `adc_flag` is set to 2, it reads the data, processes it into tens
 *   and ones digits, and controls a fan based on the received value.
 * - If the `adc_flag` is 0, it interprets the received data as control commands
 *   and performs actions such as adjusting the brightness, starting/stopping the
 *   fan, controlling a stepper motor's position, or manipulating PORTD.
 *
 * @note Make sure to set the `adc_flag` appropriately before calling this function
 * to ensure the correct behavior based on the received data.
 */
void READ_SPI(void)
{
	Receive_Data=SPDR;

	if(adc_flag==1)
	{
		Receive_Data=SPDR;
		PORTD=Receive_Data;
		adc_flag=0;
	}
	else if(adc_flag==2)
	{
		Receive_Data=SPDR;
		tensDigit = Receive_Data / 10;
		onesDigit = Receive_Data % 10;

		if(Receive_Data>40)
		{
			FAN_START();
		}
		else
		{
			FAN_STOP();
		}
		adc_flag=0;

	}
	else if(adc_flag==0)
	{
		if('9'==Receive_Data) //light
		{
			adc_flag=1;
		}
		else if('A'==Receive_Data)
		{
			adc_flag=2;
		}
		else if('1'==Receive_Data)
		{
			OCR0=254;

		}
		else if('2'==Receive_Data)
		{

			OCR0=0;


		}
		else if('3'==Receive_Data)
		{
			FAN_START();
		}
		else if('4'==Receive_Data)
		{
			FAN_STOP();
		}
		else if('5'==Receive_Data)
		{
			Stepper_Go(GO_360);
		}
		else if('6'==Receive_Data)
		{
			Stepper_Go(GO_0);

		}
		else if('7'==Receive_Data)
		{
			PORTD=0x00;
		}
		else if('8'==Receive_Data)
		{
			PORTD=0xFF;

		}
		else{}

	}
	else{}


}
/**
 * @brief Display a two-digit number on a seven-segment display.
 *
 * This function displays a two-digit number (0-99) on a seven-segment display.
 * It takes the tens and ones digits as input and sets the appropriate segments
 * on the display to represent the number.
 *
 * @param tens The tens digit of the number (0-9).
 * @param ones The ones digit of the number (0-9).
 *
 * @note This function assumes that the seven-segment display is connected to
 * specific GPIO pins, and these pins should be properly configured before
 * calling this function.
 *
 * @note Make sure to provide valid values for the tens and ones digits (0-9).
 * If invalid values are provided, the display may not show the expected result.
 */
void seg_display(u8 tens, u8 ones)
{
	//left
	DIO_PIN_WRITE_LOGIC_M(PORTA_,pin0,PIN_HIGH);
	DIO_PIN_WRITE_LOGIC_M(PORTA_,pin1,PIN_LOW);
	PORTC=0;

	PORTC=sevenSegDigits[tens];

	DIO_PIN_WRITE_LOGIC_M(PORTA_,pin0,PIN_LOW);
	DIO_PIN_WRITE_LOGIC_M(PORTA_,pin1,PIN_HIGH);
	PORTC=0;
	PORTC=sevenSegDigits[ones];


}
/**
 * @brief Start the fan by controlling GPIO pins.
 *
 * This function is used to start the fan by controlling the state of GPIO pins.
 * It sets one pin (e.g., PORTA pin 2) to a logic HIGH level while keeping another
 * pin (e.g., PORTA pin 3) at a logic LOW level. The specific GPIO pins used may
 * depend on the hardware configuration.
 *
 * @note This function assumes that the GPIO pins for controlling the fan are
 * properly configured before calling this function.
 *
 * @note Make sure to review the hardware documentation to ensure that the correct
 * GPIO pins are being controlled to start the fan.
 */
void FAN_START(void)
{
	DIO_PIN_WRITE_LOGIC_M(PORTA_,pin2,PIN_HIGH);
	DIO_PIN_WRITE_LOGIC_M(PORTA_,pin3,PIN_LOW);
}
/**
 * @brief Stop the fan by controlling GPIO pins.
 *
 * This function is used to stop the fan by controlling the state of GPIO pins.
 * It sets both pins (e.g., PORTA pin 2 and pin 3) to a logic LOW level, ensuring
 * that the fan stops running.
 *
 * @note This function assumes that the GPIO pins for controlling the fan are
 * properly configured before calling this function.
 *
 * @note Make sure to review the hardware documentation to ensure that the correct
 * GPIO pins are being controlled to stop the fan.
 */
void FAN_STOP(void)
{
	DIO_PIN_WRITE_LOGIC_M(PORTA_,pin2,PIN_LOW);
	DIO_PIN_WRITE_LOGIC_M(PORTA_,pin3,PIN_LOW);
}
/**
 * @brief Timer0 Interrupt Service Routine (ISR) for toggling a GPIO pin.
 *
 * This ISR (Interrupt Service Routine) is executed when Timer0 overflows, and it
 * is responsible for toggling the state of a specific GPIO pin (e.g., PORTA pin 4).
 * By toggling the pin state in the ISR, you can create periodic on-off blinking
 * or toggling effects.
 *
 * @note This ISR is typically associated with Timer0 overflow interrupts and is
 * executed at a specific time interval determined by the Timer0 configuration.
 *
 * @note Ensure that Timer0 is configured appropriately to generate periodic
 * interrupts, and the associated GPIO pin is properly configured for output before
 * enabling this ISR.
 *
 * @note The actual toggle rate depends on the Timer0 settings and clock frequency.
 *
 * @note Make sure to review your hardware documentation for Timer0 and GPIO pin
 * details.
 */
void MTIMER0_ISR(void)
{
	DIO_PIN_TOGGLE_LOGIC_M(PORTA_,pin4);

}
/**
 * @brief Control the movement of a stepper motor to a specified position.
 *
 * This function controls the movement of a stepper motor by toggling the GPIO
 * pins connected to the motor's coils. The movement can be either to rotate the
 * stepper motor by 360 degrees or bring it back to the 0-degree position.
 *
 * @param POS The desired position to move the stepper motor to.
 *   - `GO_360`: Rotate the stepper motor by 360 degrees.
 *   - `GO_0`: Bring the stepper motor back to the 0-degree position.
 *
 * @note This function assumes that the GPIO pins connected to the stepper motor
 * coils are properly configured for output and connected correctly to the motor.
 * Additionally, the delay between coil toggles determines the speed of the motor.
 *
 * @warning Be cautious with the delay values, as they can affect the motor's
 * speed and power consumption. Adjust the delays as needed for your specific
 * stepper motor and application.
 *
 * @see DIO_PIN_WRITE_LOGIC_M, _delay_ms
 */
void Stepper_Go(u8 POS)
{
	switch(POS)
	{
	case GO_360 :

		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin0, PIN_HIGH);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin1, PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin2, PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin3, PIN_LOW);
		_delay_ms(5);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin0,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin1,PIN_HIGH);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin3,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin2,PIN_LOW);
		_delay_ms(5);

		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin0,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin1,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin3,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin2,PIN_HIGH);
		_delay_ms(5);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin0,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin1,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin3,PIN_HIGH);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin2,PIN_LOW);
		_delay_ms(5);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin0, PIN_HIGH);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin1, PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin2, PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin3, PIN_LOW);
		_delay_ms(5);


		break;
	case GO_0 :


		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin0, PIN_HIGH);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin1, PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin2, PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin3, PIN_LOW);
		_delay_ms(5);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin0,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin1,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin3,PIN_HIGH);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin2,PIN_LOW);
		_delay_ms(5);

		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin0,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin1,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin3,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin2,PIN_HIGH);
		_delay_ms(5);

		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin0,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin1,PIN_HIGH);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin3,PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_,pin2,PIN_LOW);
		_delay_ms(5);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin0, PIN_HIGH);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin1, PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin2, PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin3, PIN_LOW);
		_delay_ms(5);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin0, PIN_HIGH);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin1, PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin2, PIN_LOW);
		DIO_PIN_WRITE_LOGIC_M(PORTB_, pin3, PIN_HIGH);
		_delay_ms(5);


		break;

	}
}
