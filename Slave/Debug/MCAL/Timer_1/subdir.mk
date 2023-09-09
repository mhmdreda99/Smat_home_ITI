################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timer_1/MCAL_TIMER1.c 

C_DEPS += \
./MCAL/Timer_1/MCAL_TIMER1.d 

OBJS += \
./MCAL/Timer_1/MCAL_TIMER1.o 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timer_1/%.o: ../MCAL/Timer_1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


