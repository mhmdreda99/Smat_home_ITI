################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SERVO/HAL_SERVE.c 

C_DEPS += \
./HAL/SERVO/HAL_SERVE.d 

OBJS += \
./HAL/SERVO/HAL_SERVE.o 


# Each subdirectory must supply rules for building sources it contributes
HAL/SERVO/%.o: ../HAL/SERVO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


