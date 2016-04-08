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
../Sonar.c \
../custom_timer.c \
../main.c \
../motion.c \
../usart_serial.c \
../wireless_interface.c 

OBJS += \
./LCD.o \
./LED.o \
./Movement.o \
./ReadTmp.o \
./Scan.o \
./Sonar.o \
./custom_timer.o \
./main.o \
./motion.o \
./usart_serial.o \
./wireless_interface.o 

C_DEPS += \
./LCD.d \
./LED.d \
./Movement.d \
./ReadTmp.d \
./Scan.d \
./Sonar.d \
./custom_timer.d \
./main.d \
./motion.d \
./usart_serial.d \
./wireless_interface.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/Users/ryanoconnor/Documents/Arduino shit/FreeRTOS801/include" -I"/Users/ryanoconnor/Documents/Arduino shit/CEG4166_RTS_Lib/include" -DGCC_MEGA_AVR -Wall -O2 -ffunction-sections -fdata-sections -mcall-prologues -mrelax -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


