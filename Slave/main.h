/**
 * @file main.h
 * @author Kareem Zidan/mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef MAIN_H_
#define MAIN_H_
/*********** include section***********/

#define GO_360   0x01
#define GO_0     0x00

#define dummy_data 0x00

/**
 * @brief Read data via SPI.
 */
void READ_SPI(void);

/**
 * @brief Interrupt Service Routine (ISR) for Timer0.
 *
 * This ISR handles Timer0 interrupts.
 */
void MTIMER0_ISR(void);

/**
 * @brief Display a two-digit number on a 7-segment display.
 *
 * @param tens The tens digit to display.
 * @param ones The ones digit to display.
 */
void seg_display(u8 tens, u8 ones);

/**
 * @brief Move a stepper motor to a specified position.
 *
 * This function controls a stepper motor to move to a specific position.
 *
 * @param POS The position to move the stepper motor to.
 */
void Stepper_Go(u8 POS);

/**
 * @brief Stop the fan.
 *
 * This function stops the operation of a fan.
 */
void FAN_STOP(void);

/**
 * @brief Start the fan.
 *
 * This function starts the operation of a fan.
 */
void FAN_START(void);


/**
 * @brief 
 * 
 */
void App_init(void);




#endif /* MAIN_H_ */
