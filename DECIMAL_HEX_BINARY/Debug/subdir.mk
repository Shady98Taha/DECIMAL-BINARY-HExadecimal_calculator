################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CALC_Program.c \
../DIO_Program.c \
../KEYPAD_Program.c \
../LCD_Program.c \
../main.c 

OBJS += \
./CALC_Program.o \
./DIO_Program.o \
./KEYPAD_Program.o \
./LCD_Program.o \
./main.o 

C_DEPS += \
./CALC_Program.d \
./DIO_Program.d \
./KEYPAD_Program.d \
./LCD_Program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


