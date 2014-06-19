################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Emac/src/emac.c \
../src/Emac/src/tcpip.c \
../src/Emac/src/webserver.c 

OBJS += \
./src/Emac/src/emac.o \
./src/Emac/src/tcpip.o \
./src/Emac/src/webserver.o 

C_DEPS += \
./src/Emac/src/emac.d \
./src/Emac/src/tcpip.d \
./src/Emac/src/webserver.d 


# Each subdirectory must supply rules for building sources it contributes
src/Emac/src/%.o: ../src/Emac/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_CMSIS=CMSIS_LPC43xx_DriverLib -D__LPC43XX__ -DLPC43_MULTICORE_M0APP -D__MULTICORE_MASTER -I"/home/pablo/Documents/CIAA-Repositories/EOPT/workspace/CIAA-Demo/src" -I"/home/pablo/Documents/CIAA-Repositories/EOPT/workspace/CIAA-Demo/src/Emac/inc" -I"/home/pablo/Documents/CIAA-Repositories/EOPT/workspace/CMSIS_LPC43xx_DriverLib/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__NEWLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


