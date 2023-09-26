################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash/flash.c 

OBJS += \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash/flash.o 

C_DEPS += \
./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash/flash.d 


# Each subdirectory must supply rules for building sources it contributes
SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash/flash.o: D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash/flash.c SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Source" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Middle-2f-flash

clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Middle-2f-flash:
	-$(RM) ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash/flash.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash/flash.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash/flash.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash/flash.su

.PHONY: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Middle-2f-flash

