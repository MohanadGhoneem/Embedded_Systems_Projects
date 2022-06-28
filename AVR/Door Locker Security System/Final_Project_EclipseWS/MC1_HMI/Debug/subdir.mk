################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../KEYPAD_Driver.c \
../LCD_Driver.c \
../MC1.c \
../MC1_Functions.c \
../Timer_Driver.c \
../UART_Driver.c 

OBJS += \
./KEYPAD_Driver.o \
./LCD_Driver.o \
./MC1.o \
./MC1_Functions.o \
./Timer_Driver.o \
./UART_Driver.o 

C_DEPS += \
./KEYPAD_Driver.d \
./LCD_Driver.d \
./MC1.d \
./MC1_Functions.d \
./Timer_Driver.d \
./UART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


