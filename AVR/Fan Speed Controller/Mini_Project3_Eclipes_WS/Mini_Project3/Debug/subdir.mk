################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Driver.c \
../DCMotor_Driver.c \
../Fan_Controller.c \
../GPIO.c \
../LCD_Driver.c \
../LM35_Driver.c \
../Timer0_PWM.c 

OBJS += \
./ADC_Driver.o \
./DCMotor_Driver.o \
./Fan_Controller.o \
./GPIO.o \
./LCD_Driver.o \
./LM35_Driver.o \
./Timer0_PWM.o 

C_DEPS += \
./ADC_Driver.d \
./DCMotor_Driver.d \
./Fan_Controller.d \
./GPIO.d \
./LCD_Driver.d \
./LM35_Driver.d \
./Timer0_PWM.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


