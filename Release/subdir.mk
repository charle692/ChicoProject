################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD.c \
../LED.c \
../Movement.c \
../ReadTmp.c \
../Scan.c \
../main.c \
../motion.c 

OBJS += \
./LCD.o \
./LED.o \
./Movement.o \
./ReadTmp.o \
./Scan.o \
./main.o \
./motion.o 

C_DEPS += \
./LCD.d \
./LED.d \
./Movement.d \
./ReadTmp.d \
./Scan.d \
./main.d \
./motion.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/Users/jayhe/Documents/CEG4166/FreeRTOS801/include" -I"/Users/jayhe/Documents/CEG4166/CEG4166_RTS_Lib/include" -DGCC_MEGA_AVR -Wall -O2 -ffunction-sections -fdata-sections -mcall-prologues -mrelax -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


