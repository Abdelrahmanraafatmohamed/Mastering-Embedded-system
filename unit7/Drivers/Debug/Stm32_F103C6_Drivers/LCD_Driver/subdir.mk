################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/LCD_Driver/lcd.c 

OBJS += \
./Stm32_F103C6_Drivers/LCD_Driver/lcd.o 

C_DEPS += \
./Stm32_F103C6_Drivers/LCD_Driver/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/LCD_Driver/lcd.o: ../Stm32_F103C6_Drivers/LCD_Driver/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"F:/Embedded course/stm_project/Drivers/Stm32_F103C6_Drivers/inc" -I"F:/Embedded course/stm_project/Drivers/Stm32_F103C6_Drivers/KEYPAD_Driver" -I"F:/Embedded course/stm_project/Drivers/Stm32_F103C6_Drivers/LCD_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/LCD_Driver/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

