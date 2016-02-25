################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD.c \
../LED.c \
../ReadTmp.c \
../main.c 

OBJS += \
./LCD.o \
./LED.o \
./ReadTmp.o \
./main.o 

C_DEPS += \
./LCD.d \
./LED.d \
./ReadTmp.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/Users/ryanoconnor/Documents/Arduino shit/FreeRTOS801/include" -I"/Users/ryanoconnor/Documents/Arduino shit/CEG4166_RTS_Lib/include" -DGCC_MEGA_AVR -Wall -O2 -ffunction-sections -fdata-sections -mcall-prologues -mrelax -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


