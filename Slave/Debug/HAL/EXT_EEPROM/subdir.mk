################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/EXT_EEPROM/HAL_EEPROM_INT.c 

C_DEPS += \
./HAL/EXT_EEPROM/HAL_EEPROM_INT.d 

OBJS += \
./HAL/EXT_EEPROM/HAL_EEPROM_INT.o 


# Each subdirectory must supply rules for building sources it contributes
HAL/EXT_EEPROM/%.o: ../HAL/EXT_EEPROM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


