################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ciaaIO.c \
../src/ciaaTest.c \
../src/cr_startup_lpc43xx.c \
../src/crp.c \
../src/sysinit.c 

OBJS += \
./src/ciaaIO.o \
./src/ciaaTest.o \
./src/cr_startup_lpc43xx.o \
./src/crp.o \
./src/sysinit.o 

C_DEPS += \
./src/ciaaIO.d \
./src/ciaaTest.d \
./src/cr_startup_lpc43xx.d \
./src/crp.d \
./src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_LPCOPEN -DNO_BOARD_LIB -D__LPC43XX__ -I"/home/pablo/Desktop/LPCOpen_workspace/lpc_chip_43xx/inc" -Og -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


