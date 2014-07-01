################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ciaaAIN.c \
../src/ciaaAOUT.c \
../src/ciaaI2C.c \
../src/ciaaIO.c \
../src/ciaaNVM.c \
../src/ciaaSPIFI.c \
../src/ciaaTest.c \
../src/ciaaUART.c \
../src/cr_startup_lpc43xx.c \
../src/crp.c \
../src/sysinit.c 

OBJS += \
./src/ciaaAIN.o \
./src/ciaaAOUT.o \
./src/ciaaI2C.o \
./src/ciaaIO.o \
./src/ciaaNVM.o \
./src/ciaaSPIFI.o \
./src/ciaaTest.o \
./src/ciaaUART.o \
./src/cr_startup_lpc43xx.o \
./src/crp.o \
./src/sysinit.o 

C_DEPS += \
./src/ciaaAIN.d \
./src/ciaaAOUT.d \
./src/ciaaI2C.d \
./src/ciaaIO.d \
./src/ciaaNVM.d \
./src/ciaaSPIFI.d \
./src/ciaaTest.d \
./src/ciaaUART.d \
./src/cr_startup_lpc43xx.d \
./src/crp.d \
./src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_LPCOPEN -DNO_BOARD_LIB -D__LPC43XX__ -I"/home/pablo/Documents/CIAA-Repositories/EOPT/workspace_lpcopen/lpc_chip_43xx/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


