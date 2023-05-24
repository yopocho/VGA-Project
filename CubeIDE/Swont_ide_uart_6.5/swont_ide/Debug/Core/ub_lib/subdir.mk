################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ub_lib/drawshapes.c \
../Core/ub_lib/drawtext.c \
../Core/ub_lib/stm32_ub_vga_screen.c 

OBJS += \
./Core/ub_lib/drawshapes.o \
./Core/ub_lib/drawtext.o \
./Core/ub_lib/stm32_ub_vga_screen.o 

C_DEPS += \
./Core/ub_lib/drawshapes.d \
./Core/ub_lib/drawtext.d \
./Core/ub_lib/stm32_ub_vga_screen.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ub_lib/%.o Core/ub_lib/%.su Core/ub_lib/%.cyclo: ../Core/ub_lib/%.c Core/ub_lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"C:/Users/niels/Documents/Homework/Jaar_3/Software Ontwikkeling/VGA_Project/CubeIDE/Swont_ide_uart_6.5/swont_ide/Core/ub_lib" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/niels/Documents/Homework/Jaar_3/Software Ontwikkeling/VGA_Project/CubeIDE/Swont_ide_uart_6.5/swont_ide/Core/Front_Layer" -I"C:/Users/niels/Documents/Homework/Jaar_3/Software Ontwikkeling/VGA_Project/CubeIDE/Swont_ide_uart_6.5/swont_ide/Core/Logic_Layer" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ub_lib

clean-Core-2f-ub_lib:
	-$(RM) ./Core/ub_lib/drawshapes.cyclo ./Core/ub_lib/drawshapes.d ./Core/ub_lib/drawshapes.o ./Core/ub_lib/drawshapes.su ./Core/ub_lib/drawtext.cyclo ./Core/ub_lib/drawtext.d ./Core/ub_lib/drawtext.o ./Core/ub_lib/drawtext.su ./Core/ub_lib/stm32_ub_vga_screen.cyclo ./Core/ub_lib/stm32_ub_vga_screen.d ./Core/ub_lib/stm32_ub_vga_screen.o ./Core/ub_lib/stm32_ub_vga_screen.su

.PHONY: clean-Core-2f-ub_lib

