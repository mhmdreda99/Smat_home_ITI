/**
 * @file HAL_EEPROM_INT.h
 * @author Kareem Zidan/mhmdreda99
 * @brief 
 * @version 0.1
 * @date 2023-09-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HAL_EXT_EEPROM_HAL_EEPROM_INT_H_
#define HAL_EXT_EEPROM_HAL_EEPROM_INT_H_

/**
 * @brief Write a string of data to the EEPROM.
 *
 * This function writes a string of data to the EEPROM, starting at the specified memory address. It iterates through the data characters, converting them to bytes, and uses the `HEEPROM_WRITE` function to write each byte to the EEPROM. A delay of 100 milliseconds is added between writes, possibly to allow the EEPROM to handle the write operations.
 *
 * @param user A pointer to the data (string) to be written.
 * @param user_length The length of the data string.
 * @param s_address The starting memory address in the EEPROM where data will be written.
 *
 * @note This function relies on the `HEEPROM_WRITE` function and assumes that the I2C communication and EEPROM hardware are properly configured and initialized. The delay between writes may be necessary to ensure that the EEPROM can handle the data write operations.
 *
 * @see HEEPROM_WRITE
 * @see _delay_ms
 */
void HEEPROM_WRITE_STRING(u8 *user,u8 user_length,u8 s_address);
/**
 * @brief Read a string of data from the EEPROM.
 *
 * This function reads a string of data from the EEPROM, starting at the specified memory address. It iterates through the EEPROM addresses, reading one byte at a time, and stores the read data in the provided buffer. It uses the `HEEPROM_READ` function to perform individual byte reads.
 *
 * @param user A pointer to the buffer where the read data (string) will be stored.
 * @param user_length The length of the data to be read.
 * @param s_address The starting memory address in the EEPROM from which data will be read.
 *
 * @note This function relies on the `HEEPROM_READ` function and assumes that the I2C communication and EEPROM hardware are properly configured and initialized.
 *
 * @see HEEPROM_READ
 */
void HEEPROM_READ_STRING(u8 *user,u8 user_length,u8 s_address);

/**
 * @brief Read a single byte of data from a specific address in the EEPROM.
 *
 * This function initiates communication with the EEPROM via the I2C protocol, sends the EEPROM's slave address with the write bit (0xA0), specifies the memory location address in the EEPROM to read from, restarts the I2C communication, sends the EEPROM's slave address with the read bit (0xA1), performs a master read operation, reads a byte of data from the EEPROM with acknowledgment, stores the read data in the provided data pointer, and finally stops the I2C communication.
 *
 * @param Address The memory address in the EEPROM from which data will be read.
 * @param data A pointer to where the read data will be stored.
 *
 * @note This function assumes that the I2C communication and EEPROM hardware are properly configured and initialized.
 *
 * @see I2C_START
 * @see I2C_WRITE
 * @see I2C_READ_WITH_ACK
 * @see I2C_STOP
 */

void HEEPROM_READ(u8 Address,u8 *data);
/**
 * @brief Write a single byte of data to a specific address in the EEPROM.
 *
 * This function initiates communication with the EEPROM via the I2C protocol, sends the EEPROM's slave address with the write bit (0xA0), specifies the memory location address in the EEPROM, writes the data byte to the specified address, and then stops the I2C communication.
 *
 * @param data The data byte to be written to the EEPROM.
 * @param address The memory address in the EEPROM where the data will be written.
 *
 * @note This function assumes that the I2C communication and EEPROM hardware are properly configured and initialized.
 *
 * @see I2C_START
 * @see I2C_WRITE
 * @see I2C_STOP
 */
void HEEPROM_WRITE(u8 data,u8 address);
#endif /* HAL_EXT_EEPROM_HAL_EEPROM_INT_H_ */
