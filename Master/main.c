/**
 * @file main.c
 * @author Kareem Zidan/mhmdreda99 (Moreda491999@gmail.com)
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
#include"MCAL/SPI/SPI_REG.h"
#include"MCAL/I2C/MCAL_I2C_INT.h"
#include"MCAL/I2C/MCAL_I2C_REG.h"
#include"HAL/EXT_EEPROM/HAL_EEPROM_INT.h"
#include"HAL/LCD/hal_lcd_interface.h"
#include"HAL/KEYPAD/keypad_interface.h"
#include"RTOS/RTOS_INT.h"
#include "MCAL/M_ADC_INT.h"



/***********kp data types*********/
button_state_t kp_state;
char kp_val=0;
u8 USER_POS_=0;
u8 PASS_POS=0;
u8 PASS_POS_=0;
u8 compared_password_pos;
/***********kp data types*********/
u8 tasks_state=0;
u16 counter;
/***********comparing data types***********/
u8 DEF_USER[4]={0};
u8 DEF_EEPROM[4]={0};
u8 DEF_PASSWORD[4]={0};
u8 number_Of_user=0;
u8 New_User_Address;
/***********comparing data types***********/
int entry=0;
int OPEN_CHANGE_FLAG=0;
SIGN_STATE_T SIGN_STATE=ENTER_USER;
/**********FUNCTION DECLERATION*********/
/***********adc***********/
u16 LDR_VAL=0;
u16 LM35_VAL=0;
u8 temp;
u8 Light_val;

/**********FUNCTION DECLERATION*********/
int main()
{
	PORT_DIRECTION_INIT();
	PORT_LOGICLEVEL_INIT();
	RTOS_INIT();
	HLCD_INIT_4bit();
	MSPI_Init(NULL);
	I2C_INIT(NULL);
	MUART_INIT(NULL,NULL,NULL);
	MADC_voidInit();
	HEEPROM_READ(0xFF,&number_Of_user);
	IDLE_FRAME();
	while(1)
	{

		kp_state=keypad_readd(&kp_val);
		if(BUTTON_PRESSED==kp_state)
		{
			if(entry==0)
			{
				IDLE_STATE();
				entry=1;
			}
			else if(entry==1)/*else if we are not in entry mode*/
			{
				if(OPEN_CHANGE_FLAG==1) // Open System
				{
					if(SIGN_STATE==ENTER_USER)
					{
						SIGN_STATE=GET_ACCOUNT(USER);
					}
					else if(SIGN_STATE==ENTER_PASSWORD)
					{
						SIGN_STATE=GET_ACCOUNT(PASS);
						if(SIGN_STATE==SYS_OPENED)
						{
							SIGN_STATE=SYSTEM_STARTED;
						}
					}
				}
				else if(OPEN_CHANGE_FLAG==2) // change password
				{
					if(SIGN_STATE==ENTER_USER)
					{
						SIGN_STATE=GET_ACCOUNT(USER);
					}
					else if(SIGN_STATE==ENTER_PASSWORD)
					{
						SIGN_STATE=GET_ACCOUNT(PASS);
						if(SIGN_STATE==SYS_OPENED)
						{
							ENTER_NEW_PASS_FRAME();
						}
					}
					else if(SIGN_STATE==SYS_OPENED)
					{
						SIGN_STATE=CHANGE_PASSWORD();
						if(SIGN_STATE==PASSWORD_CHANGED)
						{
							OPEN_CHANGE_FLAG=0;
							entry=0;
							kp_val=0;
							SIGN_STATE=ENTER_USER;
							HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
							IDLE_FRAME();
						}
					}
					else{}
				}
				else if(OPEN_CHANGE_FLAG==3)//add user
				{
					if(SIGN_STATE==ENTER_USER)
					{
						SIGN_STATE=GET_NEW_USER();
					}
					else if(USER_SETTED==SIGN_STATE)
					{
						SIGN_STATE=GET_NEW_PASS();
					}
				}
			}
			else{
			}
		}
		else if((BUTTON_RELEASED==kp_state)&&(SYSTEM_STARTED==SIGN_STATE))
		{


			RTOS_START();

		}
		else{}


	}
}
/**********************************************************/
/**
 * @brief Compare entered username with stored usernames.
 *
 * This function compares the entered username (`DEF_USER`) with stored usernames in EEPROM
 * to verify user access. It iterates through the stored usernames and compares them character by character.
 * If a match is found, the function transitions to the password entry state and sets up the necessary variables.
 * If the username is incorrect, it displays an error message and increments the user attempt counter.
 * If the maximum number of attempts is reached, it clears the input and returns to the idle state.
 *
 * @return Current state:
 *         - ENTER_USER: The function is in the user entry state.
 *         - ENTER_PASSWORD: The function is in the password entry state.
 *         - SYS_OPENED: The system is opened, and user access is granted.
 */
u8 COMPARE_USER(void)
{
	static int user_pos=0;
	u8 required_user_flag=0;
	int user=PROCESS_USER;
	for(int y=0;y<number_Of_user;y++)
	{
		user=PROCESS_USER;
		for(int i =0 ; i <=3 ; ++i)
		{
			HEEPROM_READ((y*FIRST_USER)+i,&DEF_EEPROM[i]);
			if(DEF_USER[i]==DEF_EEPROM[i])
			{

			}
			else
			{
				user=ENTER_USER;
				break;
			}
		}
		if(user==PROCESS_USER)
		{
			user=ENTER_PASSWORD;
			ENTER_PASS_FRAME();
			user_pos=0;
			compared_password_pos=(y*FIRST_USER);
			break;
		}
	}
	if(user==ENTER_USER)
	{
		user_pos++;
		user=ENTER_USER;
		WRONG_USER_FRAME(user_pos);
		_delay_ms(1000);
	}


	if(user_pos==3)
	{
		entry=0;
		memset(DEF_USER,0,4);
		memset(DEF_PASSWORD,0,4);
		SIGN_STATE=ENTER_USER;
		IDLE_FRAME();
		user_pos=0;
	}
	else if((user_pos!=0)&&(user_pos!=3))
	{
		HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
		ENTER_USER_FRAME();
		SIGN_STATE=ENTER_USER;
		user=ENTER_USER;
	}
	else
	{

	}
	return user;
}
/**
 * @brief Compare entered password with stored password.
 *
 * This function compares the entered password (`DEF_PASSWORD`) with the stored password
 * in EEPROM to verify user access. It iterates through the characters of the entered
 * password and compares them with the stored password character by character. If a character
 * doesn't match, it displays an error message, increments the password attempt counter, and
 * waits for a brief period. If the maximum number of attempts is reached, it clears the input
 * and returns to the idle state. If the password is correct, it displays a success message
 * and grants access to the system.
 *
 * @return Current state:
 *         - ENTER_PASSWORD: The function is in the password entry state.
 *         - SYS_OPENED: The system is opened, and user access is granted.
 *         - ENTER_USER: The function transitions to the user entry state.
 */
u8 COMPARE_PASSWORD(void)
{
	int user=PROCESS_PASSWORD;
	static int pass_pos=0;
	for(int i =0 ; i <=3; ++i)
	{
		HEEPROM_READ((compared_password_pos+4+i),&DEF_EEPROM[i]);


		if(DEF_PASSWORD[i]==DEF_EEPROM[i])
		{

		}
		else
		{
			pass_pos++;
			user=ENTER_PASSWORD;
			WRONG_PASS_FRAME(pass_pos);
			_delay_ms(1000);
			break;
		}
	}
	if(user==PROCESS_PASSWORD)
	{
		HLCD_Send_String_4bit((u8 *)"SYS OPEND");
		pass_pos=0;
		user=SYS_OPENED;
	}
	else
	{
		if(pass_pos==3)
		{
			entry=0;
			memset(DEF_USER,0,4);
			memset(DEF_PASSWORD,0,4);
			USER_POS_=0;
			PASS_POS_=0;
			user=ENTER_USER;
			pass_pos=0;
			IDLE_FRAME();
		}
		else if((pass_pos!=0)&&(pass_pos!=3))
		{
			HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
			ENTER_PASS_FRAME();
			user=ENTER_PASSWORD;
		}
		else
		{}
	}
	return user;
}
/*****************LCD_FRAMES****************/

void IDLE_FRAME(void)
{
	/*
	 *  1- Open SmartSystem
   2- Change Password
   3- Add User
	 */
	HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
	HLCD_Send_String_Position_4bit((u8 *)"2->Open Sys",LCD_GO_ROW2,0x00);
	HLCD_Send_String_Position_4bit((u8 *)"3->..",LCD_GO_ROW2,0x0C);
	HLCD_Send_String_Position_4bit((u8 *)"1->Change Pass",LCD_GO_ROW1,0x00);
}


/*****************LCD_FRAMES****************/

void SET_DEFAULT_USER_PASS(void)
{
	HEEPROM_WRITE_STRING((u8 *)"1234",4,0x00);
	HEEPROM_WRITE_STRING((u8 *)"1234",4,0x04);
}
/*********************************************/

void ENTER_USER_FRAME(void)
{
	HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
	HLCD_Send_String_4bit((u8*)"Enter User");
	HLCD_Send_CursorPosition_4bit(LCD_GO_ROW2,0x00);
}
/*********************************************/
void ENTER_PASS_FRAME(void)
{
	HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
	HLCD_Send_String_4bit((u8*)"Enter PASSWORD");
	HLCD_Send_CursorPosition_4bit(LCD_GO_ROW2,0x00);
}
/*********************************************/
void CHANGE_PASSWORD_FRAME(void)
{
	HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
	HLCD_Send_String_Position_4bit((u8 *)"ENTER USER YOU",LCD_GO_ROW1,0x01);
	HLCD_Send_String_Position_4bit((u8 *)"WANT TO CHANGE",LCD_GO_ROW2,0x01);
	_delay_ms(1000);
	HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
	HLCD_Send_String_Position_4bit((u8 *)"ENTER USER ",LCD_GO_ROW1,0x00);
	HLCD_Send_CursorPosition_4bit(LCD_GO_ROW2,0x00);


}
/************SECURITY SYS API's**************/
void ADD_USER_FRAME(void)
{
	HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
	HLCD_Send_String_Position_4bit((u8 *)"ENTER USER ",LCD_GO_ROW1,0x03);
	HLCD_Send_CursorPosition_4bit(LCD_GO_ROW2,0x00);
}


void WRONG_PASS_FRAME(u8 pass)
{
	HLCD_Send_String_4bit((u8 *)"WRONG PASS");
	HLCD_Send_String_Position_4bit((u8 *)"For ->",LCD_GO_ROW2,0x00);
	HLCD_Send_char_Position_4bit(pass+'0',LCD_GO_ROW2,0x8);
	HLCD_Send_String_Position_4bit((u8 *)"/3 Times",LCD_GO_ROW2,0x0A);
}
/*********************************************************************/
void ENTER_NEW_PASS_FRAME(void)
{
	HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
	HLCD_Send_String_4bit((u8*)"ENTER NEW PASS");
	HLCD_Send_CursorPosition_4bit(LCD_GO_ROW2,0x00);
}
/*********************************************************************/
void WRONG_USER_FRAME(u8 pass)
{
	HLCD_Send_String_4bit((u8 *)"WRONG USER");
	HLCD_Send_String_Position_4bit((u8 *)"For ->",LCD_GO_ROW2,0x00);
	HLCD_Send_char_Position_4bit(pass+'0',LCD_GO_ROW2,0x8);
	HLCD_Send_String_Position_4bit((u8 *)"/3 Times",LCD_GO_ROW2,0x0A);
}
/************SECURITY SYS API's**************/
/**
 * @brief Get user account information (username or password).
 *
 * This function is used to retrieve user account information, either the username or the password,
 * depending on the `USER_OR_PASS` parameter. It processes user input, stores the information in memory,
 * and returns the current state based on the input.
 *
 * @param USER_OR_PASS Specify whether to get the username or password (USER or PASS).
 * @return Current state:
 *         - ENTER_USER: The function is in the user entry state.
 *         - ENTER_PASSWORD: The function is in the password entry state.
 *         - SYS_OPENED: The system is opened, and user access is granted.
 *         - COMPARE_USER: User information comparison is in progress.
 *         - COMPARE_PASSWORD: Password comparison is in progress.
 */
u8 GET_ACCOUNT(u8 USER_OR_PASS)
{
	SIGN_STATE_T pass_flag=ENTER_USER;
	switch(USER_OR_PASS)
	{
	case USER :
		DEF_USER[USER_POS_]=kp_val-'0';
		HLCD_Send_char_4bit(kp_val);
		USER_POS_++;
		if(USER_POS_==4)
		{
			USER_POS_=0;
			HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
			pass_flag=COMPARE_USER();
		}
		break;
	case PASS:
		DEF_PASSWORD[PASS_POS_]=kp_val-'0';
		HLCD_Send_char_4bit(kp_val);
		PASS_POS_++;
		pass_flag=ENTER_PASSWORD;
		if(PASS_POS_==4)
		{
			pass_flag=SYS_OPENED;
			PASS_POS_=0;
			HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
			pass_flag=COMPARE_PASSWORD();
		}
		break;

	default : break;
	}
	return pass_flag;
}

/******************************************************/
void ACCOUNT_CHECK(void)
{




}
/******************************************************/
/**
 * @brief Change the system password.
 *
 * This function is responsible for changing the system password. It processes user input and sets
 * the new password in memory.
 *
 * @param None
 * @return Status code:
 *         - SYS_OPENED: The system is opened.
 *         - PASSWORD_CHANGED: The password has been successfully changed.
 */
u8 CHANGE_PASSWORD(void)
{
	u8 STATUS=SYS_OPENED;
	HLCD_Send_char_4bit(kp_val);
	DEF_PASSWORD[PASS_POS]=kp_val;
	PASS_POS++;
	if(PASS_POS==4)
	{
		HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
		HEEPROM_WRITE_STRING(&DEF_PASSWORD,4,compared_password_pos+0x04);
		HLCD_Send_String_4bit((u8 *)"New Pass Has Set");
		_delay_ms(1000);
		PASS_POS=0;
		STATUS=PASSWORD_CHANGED;

	}
	return STATUS;
}
/**
 * @brief Handle the idle state of the system and process user input.
 *
 * This function is responsible for handling the system's idle state, where the user can choose
 * to open the system, change the password, or add a new user. It processes user input and sets
 * appropriate flags for further actions.
 *
 * Supported input:
 * - '1': Change password mode.
 * - '2': Open the system mode.
 * - '3': Add a new user mode.
 *
 * @note The function sets flags to indicate the selected mode, and further processing should be
 *       handled based on these flags.
 *
 * @return None
 */
void IDLE_STATE(void)
{

	if('2'==kp_val) // Open System
	{
		ENTER_USER_FRAME();
		OPEN_CHANGE_FLAG=1;
	}
	else if('1'==kp_val) // change password
	{
		CHANGE_PASSWORD_FRAME();
		OPEN_CHANGE_FLAG=2;
	}
	else if ('3'==kp_val)//add user
	{
		ADD_USER_FRAME();
		OPEN_CHANGE_FLAG=3;
	}
	else{/*else of entry kp_val is not 1 or 2*/}
	//	entry=1;
}
/**
 * @brief Handle commands received via Bluetooth and perform corresponding actions.
 *
 * This function reads characters from the UART (Bluetooth) using polling and processes
 * the received commands. Depending on the received command, it sends corresponding
 * data or triggers specific actions over the SPI interface (Master-Slave Communication).
 *
 * Supported commands:
 * - '1': Send data '1' over SPI.
 * - '2': Send data '2' over SPI.
 * - '3': Send data '3' over SPI.
 * - '4': Send data '4' over SPI.
 * - '5': Send data '5' over SPI.
 * - '6': Send data '6' over SPI.
 * - '7': Send data '7' over SPI.
 * - '8': Send data '8' over SPI.
 *
 * @note Make sure that the UART and SPI interfaces are properly initialized before calling this function.
 *
 * @return None
 */
void BLUETOOTH_SYSTEM_OPENED(void)
{
	char data;
	data=UART_RECEIVE_CHAR_POOLING();
	if('1'==data)
	{
		MSPI_TRANSCIEVE_BLOCKING('1');
	}
	else if('2'==data)
	{
		MSPI_TRANSCIEVE_BLOCKING('2');
	}
	else if('3'==data)
	{
		MSPI_TRANSCIEVE_BLOCKING('3');

	}
	else if('4'==data)
	{
		MSPI_TRANSCIEVE_BLOCKING('4');


	}
	else if('5'==data)
	{
		MSPI_TRANSCIEVE_BLOCKING('5');


	}
	else if('6'==data)
	{
		MSPI_TRANSCIEVE_BLOCKING('6');


	}
	else if('7'==data)
	{
		MSPI_TRANSCIEVE_BLOCKING('7');
	}
	else if('8'==data)
	{
		MSPI_TRANSCIEVE_BLOCKING('8');
	}
}
/**
 * @brief Read light intensity from an LDR sensor and calculate the corresponding value.
 *
 * This function reads the analog value from an LDR (Light Dependent Resistor) sensor connected
 * to the specified ADC channel (CHANNEL_1). It then calculates the corresponding light intensity
 * value using the provided mapping function, and stores the result in the global variable `Light_val`.
 *
 * @note Before calling this function, ensure that the ADC (Analog-to-Digital Converter) is
 * initialized properly, and the LDR sensor is connected to the correct channel.
 *
 * @return None
 */
void READ_LDR(void)
{

	LDR_VAL=MADC_u16_GetVal_BLOCKING(CHANNEL_1);
	Light_val=Mapping_Values(255,0,1023,0,LDR_VAL);
}
/**
 * @brief Read temperature from LM35 sensor and calculate the temperature value.
 *
 * This function reads the analog value from an LM35 temperature sensor connected to
 * the specified ADC channel (CHANNEL_2). It then calculates the corresponding temperature
 * value using the LM35 sensor's characteristics. The temperature value is stored in the
 * global variable `temp`.
 *
 * @note Before calling this function, ensure that the ADC (Analog-to-Digital Converter) is
 * initialized properly, and the LM35 sensor is connected to the correct channel.
 *
 * @return None
 */
void READ_LM35(void)
{

	LM35_VAL=MADC_u16_GetVal_BLOCKING(CHANNEL_2);
	temp=Mapping_Values(99,0,1023,0,LM35_VAL);
}
/**
 * @brief Send data over the Serial Peripheral Interface (SPI).
 *
 * This function is responsible for sending data over the Serial Peripheral Interface (SPI).
 * It uses the Microchip SPI library to transmit data sequentially. In this case, it sends
 * temperature (in `temp`) and light level (in `Light_val`) data over SPI.
 *
 * @note Before calling this function, ensure that the SPI interface is initialized properly
 * using MSPI_Init.
 *
 * @param None
 *
 * @return None
 */
void SPI_SEND(void)
{
	DIO_PIN_WRITE_LOGIC_M(PORTD_,pin2,PIN_LOW);
	MSPI_TRANSCIEVE_BLOCKING('A');
	MSPI_TRANSCIEVE_BLOCKING(temp);
	MSPI_TRANSCIEVE_BLOCKING('9');
	MSPI_TRANSCIEVE_BLOCKING(Light_val);


//	DIO_PIN_WRITE_LOGIC_M(PORTD_,pin2,PIN_HIGH);

}
/**
 * @brief Initialize the Real-Time Operating System (RTOS) tasks.
 *
 * This function initializes the tasks for the Real-Time Operating System (RTOS). It
 * sets up different tasks with their respective priorities and time intervals. These
 * tasks are essential for managing various aspects of the system, such as reading
 * sensor data, communicating over SPI, and controlling external devices.
 *
 * @note This function should be called once during the system's initialization to set
 * up the RTOS tasks. The RTOS tasks will run concurrently based on their priorities
 * and time intervals.
 *
 * @see Create_Task, BLUETOOTH_SYSTEM_OPENED, READ_LDR, READ_LM35, SPI_SEND
 */
void RTOS_INIT(void)
{

	tasks_state=Create_Task(1,100,0,&BLUETOOTH_SYSTEM_OPENED);
	tasks_state&=Create_Task(0,250,250,&READ_LDR);
	tasks_state&=Create_Task(2,250,0,&READ_LM35);
	tasks_state&=Create_Task(3,600,0,&SPI_SEND);

}
/**
 * @brief Set a new password for the currently selected user.
 *
 * This function allows you to set a new password for the currently selected user.
 * The user is prompted to enter a 4-digit password through keypad input. Once the
 * password is entered and confirmed, it is stored securely for the user.
 *
 * @return The status of the password setting process:
 *   - `USER_SETTED`: The password has been successfully set, and the user can
 *     proceed to use the system.
 *   - `ENTER_USER`: Awaiting the user to enter the user ID.
 *
 * @note This function assumes that a keypad input is used to enter the password and
 * that a display (such as an LCD) is used to show prompts and messages during the
 * password setting process.
 *
 * @warning Ensure that the password is stored securely, and consider implementing
 * additional security measures as needed for your specific application.
 *
 * @see HEEEPROM_WRITE_STRING, HLCD_Send_Command_4bit, HLCD_Send_String_4bit, IDLE_FRAME,
 *   USER_SETTED
 */
u8 GET_NEW_PASS(void)
{
	static u8 S_address;
	if(USER_POS_==0)
	{
		S_address=(number_Of_user*FIRST_USER);
	}

	u8 STATUS=USER_SETTED;
	HLCD_Send_char_4bit(kp_val);
	DEF_PASSWORD[PASS_POS_]=kp_val;
	PASS_POS_++;
	if(PASS_POS_==4)
	{
		HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
		HEEPROM_WRITE_STRING(&DEF_PASSWORD,4,S_address+0x04);
		PASS_POS_=0;
		STATUS=ENTER_USER;
		entry=0;
		++number_Of_user;
		HEEPROM_WRITE(number_Of_user,0xFF);
		HLCD_Send_String_4bit((u8 *)"New User Has Set");
		_delay_ms(1000);
		entry=0;
		USER_POS_=0;
		PASS_POS_=0;
		IDLE_FRAME();

	}
	return STATUS;
}
/**
 * @brief Add a new user with a specified user ID.
 *
 * This function allows you to add a new user with a unique user ID by entering
 * the user ID through a keypad input. Once the user ID is entered and confirmed,
 * the user is prompted to enter a password.
 *
 * @return The status of the user entry process:
 *   - `ENTER_USER`: Awaiting the user to enter the user ID.
 *   - `USER_SETTED`: The user ID has been successfully set, and the user is prompted
 *     to enter a password.
 *
 * @note This function assumes that a keypad input is used to enter the user ID, and it
 * also assumes that a display (such as an LCD) is used to show prompts and messages
 * during the user entry process.
 *
 * @warning Ensure that the user ID and password are stored securely, and consider
 * implementing additional security measures as needed for your specific application.
 *
 * @see HEEEPROM_WRITE_STRING, HLCD_Send_Command_4bit, HLCD_Send_String_4bit,
 *   HLCD_Send_CursorPosition_4bit, USER_SETTED
 */
u8 GET_NEW_USER(void)
{
	//	static u8 number_Of_user;
	static u8 S_address;
	if(USER_POS_==0)
	{
		S_address=(number_Of_user*FIRST_USER);
	}
	u8 STATUS=ENTER_USER;
	HLCD_Send_char_4bit(kp_val);
	DEF_USER[USER_POS_]=kp_val;
	USER_POS_++;
	if(USER_POS_==4)
	{
		HEEPROM_WRITE_STRING(&DEF_USER,4,S_address);
		HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
		HLCD_Send_String_4bit((u8 *)"ENTER PASSWORD");
		HLCD_Send_CursorPosition_4bit(LCD_GO_ROW2,0x00);
		USER_POS_=0;
		STATUS=USER_SETTED;
	}

	return STATUS;
}
