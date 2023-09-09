/**
 * @file main.h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/*********** include section***********/
#ifndef MAIN_H_
#define MAIN_H_
/******Preprocessor Constants*******************/
#define USER 1
#define PASS 2
#define WRONG   1
#define CORRECT 3
#define IDLE    2
#define FIRST_USER   0x08

typedef enum
{
	ENTER_USER=4,
	PROCESS_USER,
	ENTER_PASSWORD,
	SYS_OPENED,
	PROCESS_PASSWORD,
	PASSWORD_CHANGED,
	SYSTEM_STARTED,
	PASSWORD_SETTED,
	USER_SETTED
}SIGN_STATE_T;

/**********FUNCTION DECLERATION*********/
/**
 * @brief Function to handle the idle state.
 *
 * This function handles the idle state of the system.
 */
void IDLE_STATE(void);

/**
 * @brief Compare the entered password with the stored one.
 *
 * This function compares the entered password with the stored password.
 *
 * @return Returns the comparison result (0 if equal, non-zero otherwise).
 */
u8 COMPARE_PASSWORD(void);

/**
 * @brief Compare the entered user with the stored one.
 *
 * This function compares the entered user with the stored user.
 *
 * @return Returns the comparison result (0 if equal, non-zero otherwise).
 */
u8 COMPARE_USER(void);

/**
 * @brief Change the user's password.
 *
 * This function allows the user to change their password.
 */
u8 CHANGE_PASSWORD(void);

/**
 * @brief Display the change password frame on the LCD.
 */
void CHANGE_PASSWORD_FRAME(void);

/**
 * @brief Display the enter password frame on the LCD.
 */
void ENTER_PASS_FRAME(void);

/**
 * @brief Set default user and password.
 *
 * This function sets the default user and password in EEPROM.
 */
void SET_DEFAULT_USER_PASS(void);

/**
 * @brief Get user account information.
 *
 * This function retrieves user account information (user or password).
 *
 * @param USER_OR_PASS Specifies whether to retrieve user or password.
 * @return Returns the account information.
 */
u8 GET_ACCOUNT(u8 USER_OR_PASS);

/**
 * @brief Display the idle frame on the LCD.
 */
void IDLE_FRAME(void);

/**
 * @brief Display the enter user frame on the LCD.
 */
void ENTER_USER_FRAME(void);

/**
 * @brief Check user account.
 */
void ACCOUNT_CHECK(void);

/**
 * @brief Display the add user frame on the LCD.
 */
void ADD_USER_FRAME(void);

/**
 * @brief Display a frame for wrong password attempts.
 *
 * @param pass The number of incorrect password attempts.
 */
void WRONG_PASS_FRAME(u8 pass);

/**
 * @brief Display a frame for wrong user attempts.
 *
 * @param pass The number of incorrect user attempts.
 */
void WRONG_USER_FRAME(u8 pass);

/**
 * @brief Display the enter new password frame on the LCD.
 */
void ENTER_NEW_PASS_FRAME(void);

/**
 * @brief Handle actions when the Bluetooth system is opened.
 */
void BLUETOOTH_SYSTEM_OPENED(void);

/**
 * @brief Initialize the real-time operating system (RTOS).
 */
void RTOS_INIT(void);

/**
 * @brief Read LM35 sensor data.
 */
void READ_LM35(void);

/**
 * @brief Read LDR sensor data.
 */
void READ_LDR(void);

/**
 * @brief Get a new user.
 *
 * This function allows adding a new user.
 *
 * @return Returns the status of adding a new user.
 */
u8 GET_NEW_USER(void);

/**
 * @brief Get a new password for a user.
 *
 * This function allows setting a new password for a user.
 *
 * @return Returns the status of setting a new password.
 */
u8 GET_NEW_PASS(void);

/**
 * @brief Send data via SPI.
 */
void SPI_SEND(void);
/**
 * @brief 
 * 
 */
void App_init(void);




#endif /* MAIN_H_ */
