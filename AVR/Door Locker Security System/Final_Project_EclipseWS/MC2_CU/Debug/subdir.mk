################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buzzer_Driver.c \
../DCMotor_Driver.c \
../EEPROM_Driver.c \
../MC2.c \
../MC2_Functions.c \
../TWI_Driver.c \
../Timer_Driver.c \
../UART_Driver.c 

OBJS += \
./Buzzer_Driver.o \
./DCMotor_Driver.o \
./EEPROM_Driver.o \
./MC2.o \
./MC2_Functions.o \
./TWI_Driver.o \
./Timer_Driver.o \
./UART_Driver.o 

C_DEPS += \
./Buzzer_Driver.d \
./DCMotor_Driver.d \
./EEPROM_Driver.d \
./MC2.d \
./MC2_Functions.d \
./TWI_Driver.d \
./Timer_Driver.d \
./UART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


