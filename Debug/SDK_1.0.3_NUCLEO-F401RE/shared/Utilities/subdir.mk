################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/buff.c \
D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/utilities.c 

OBJS += \
./SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/buff.o \
./SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/utilities.o 

C_DEPS += \
./SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/buff.d \
./SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/utilities.d 


# Each subdirectory must supply rules for building sources it contributes
SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/buff.o: D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/buff.c SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Source" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/utilities.o: D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/utilities.c SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Source" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/flash" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"D:/STM32/STM32_lib/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Utilities

clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Utilities:
	-$(RM) ./SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/buff.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/buff.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/buff.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/buff.su ./SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/utilities.cyclo ./SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/utilities.d ./SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/utilities.o ./SDK_1.0.3_NUCLEO-F401RE/shared/Utilities/utilities.su

.PHONY: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2f-shared-2f-Utilities

