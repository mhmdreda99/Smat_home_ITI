################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/External_Interrupt/MCAL_EXT_INT.c 

C_DEPS += \
./MCAL/External_Interrupt/MCAL_EXT_INT.d 

OBJS += \
./MCAL/External_Interrupt/MCAL_EXT_INT.o 


# Each subdirectory must supply rules for building sources it contributes
MCAL/External_Interrupt/%.o: ../MCAL/External_Interrupt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


