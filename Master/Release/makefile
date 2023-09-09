################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include RTOS/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/Timer_1/subdir.mk
-include MCAL/Timer_0/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/MCAL_WDT/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/GLOBAL_INTERRUPT/subdir.mk
-include MCAL/External_Interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/subdir.mk
-include HAL/SERVO/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/EXT_EEPROM/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(I_DEPS)),)
-include $(I_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(M_DEPS)),)
-include $(M_DEPS)
endif
ifneq ($(strip $(MI_DEPS)),)
-include $(MI_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
FINAL_PROJECT.lss \

FLASH_IMAGE += \
FINAL_PROJECT.hex \

EEPROM_IMAGE += \
FINAL_PROJECT.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: FINAL_PROJECT.elf secondary-outputs

# Tool invocations
FINAL_PROJECT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,FINAL_PROJECT.map -mmcu=atmega32 -o "FINAL_PROJECT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FINAL_PROJECT.lss: FINAL_PROJECT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FINAL_PROJECT.elf  >"FINAL_PROJECT.lss"
	@echo 'Finished building: $@'
	@echo ' '

FINAL_PROJECT.hex: FINAL_PROJECT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex FINAL_PROJECT.elf  "FINAL_PROJECT.hex"
	@echo 'Finished building: $@'
	@echo ' '

FINAL_PROJECT.eep: FINAL_PROJECT.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex FINAL_PROJECT.elf  "FINAL_PROJECT.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: FINAL_PROJECT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 FINAL_PROJECT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(M_DEPS)$(MI_DEPS)$(S_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(ELFS)$(I_DEPS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(SIZEDUMMY)$(S_UPPER_DEPS) FINAL_PROJECT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
