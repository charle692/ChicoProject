################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ProjectTemplate.lss \

FLASH_IMAGE += \
ProjectTemplate.hex \

EEPROM_IMAGE += \
ProjectTemplate.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ProjectTemplate.elf secondary-outputs

dependents:
	-cd /Users/jayhe/Documents/CEG4166/FreeRTOS801/Release && $(MAKE) clean all
	-cd /Users/jayhe/Documents/CEG4166/CEG4166_RTS_Lib/Release && $(MAKE) clean all

# Tool invocations
ProjectTemplate.elf: $(OBJS) $(USER_OBJS) /Users/jayhe/Documents/CEG4166/FreeRTOS801/Release/libFreeRTOS801.a /Users/jayhe/Documents/CEG4166/CEG4166_RTS_Lib/Release/libCEG4166_RTS_Lib.a
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ProjectTemplate.map --gc-sections -Wl,-u,vfprintf -Wl -L"/Users/jayhe/Documents/CEG4166/FreeRTOS801/Release" -L"/Users/jayhe/Documents/CEG4166/CEG4166_RTS_Lib/Release" -mmcu=atmega2560 -o "ProjectTemplate.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ProjectTemplate.lss: ProjectTemplate.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ProjectTemplate.elf  >"ProjectTemplate.lss"
	@echo 'Finished building: $@'
	@echo ' '

ProjectTemplate.hex: ProjectTemplate.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ProjectTemplate.elf  "ProjectTemplate.hex"
	@echo 'Finished building: $@'
	@echo ' '

ProjectTemplate.eep: ProjectTemplate.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ProjectTemplate.elf  "ProjectTemplate.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ProjectTemplate.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 ProjectTemplate.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) ProjectTemplate.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:
/Users/jayhe/Documents/CEG4166/FreeRTOS801/Release/libFreeRTOS801.a:
/Users/jayhe/Documents/CEG4166/CEG4166_RTS_Lib/Release/libCEG4166_RTS_Lib.a:

-include ../makefile.targets
