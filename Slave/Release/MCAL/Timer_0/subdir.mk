################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timer_0/MCAL_TIMER0.c 

C_DEPS += \
./MCAL/Timer_0/MCAL_TIMER0.d 

OBJS += \
./MCAL/Timer_0/MCAL_TIMER0.o 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timer_0/%.o: ../MCAL/Timer_0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


