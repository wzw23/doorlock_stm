################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../icode/step_motor/step_motor.c 

OBJS += \
./icode/step_motor/step_motor.o 

C_DEPS += \
./icode/step_motor/step_motor.d 


# Each subdirectory must supply rules for building sources it contributes
icode/step_motor/%.o icode/step_motor/%.su icode/step_motor/%.cyclo: ../icode/step_motor/%.c icode/step_motor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4P5xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-icode-2f-step_motor

clean-icode-2f-step_motor:
	-$(RM) ./icode/step_motor/step_motor.cyclo ./icode/step_motor/step_motor.d ./icode/step_motor/step_motor.o ./icode/step_motor/step_motor.su

.PHONY: clean-icode-2f-step_motor

