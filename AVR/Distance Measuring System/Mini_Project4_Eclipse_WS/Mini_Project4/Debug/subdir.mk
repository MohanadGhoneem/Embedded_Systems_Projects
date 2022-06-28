################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Distance_Measurement.c \
../GPIO.c \
../ICU_Driver.c \
../LCD_Driver.c \
../Ultrasonic_Driver.c 

OBJS += \
./Distance_Measurement.o \
./GPIO.o \
./ICU_Driver.o \
./LCD_Driver.o \
./Ultrasonic_Driver.o 

C_DEPS += \
./Distance_Measurement.d \
./GPIO.d \
./ICU_Driver.d \
./LCD_Driver.d \
./Ultrasonic_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


