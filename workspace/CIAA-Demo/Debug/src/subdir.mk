################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ciaaAIN.c \
../src/ciaaAOUT.c \
../src/ciaaI2C.c \
../src/ciaaIO.c \
../src/ciaaUART.c \
../src/cr_start_m0.c \
../src/cr_startup_lpc43xx.c \
../src/crp.c \
../src/database.c \
../src/main.c 

OBJS += \
./src/ciaaAIN.o \
./src/ciaaAOUT.o \
./src/ciaaI2C.o \
./src/ciaaIO.o \
./src/ciaaUART.o \
./src/cr_start_m0.o \
./src/cr_startup_lpc43xx.o \
./src/crp.o \
./src/database.o \
./src/main.o 

C_DEPS += \
./src/ciaaAIN.d \
./src/ciaaAOUT.d \
./src/ciaaI2C.d \
./src/ciaaIO.d \
./src/ciaaUART.d \
./src/cr_start_m0.d \
./src/cr_startup_lpc43xx.d \
./src/crp.d \
./src/database.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_CMSIS=CMSIS_LPC43xx_DriverLib -D__LPC43XX__ -DLPC43_MULTICORE_M0APP -D__MULTICORE_MASTER -I"/home/pablo/Documents/CIAA-Repositories/EOPT/workspace/CIAA-Demo/src" -I"/home/pablo/Documents/CIAA-Repositories/EOPT/workspace/CIAA-Demo/src/Emac/inc" -I"/home/pablo/Documents/CIAA-Repositories/EOPT/workspace/CMSIS_LPC43xx_DriverLib/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cr_startup_lpc43xx.o: ../src/cr_startup_lpc43xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_CMSIS=CMSIS_LPC43xx_DriverLib -D__LPC43XX__ -DLPC43_MULTICORE_M0APP -D__MULTICORE_MASTER -I"/home/pablo/Documents/CIAA-Repositories/EOPT/workspace/CIAA-Demo/src" -I"/home/pablo/Documents/CIAA-Repositories/EOPT/workspace/CIAA-Demo/src/Emac/inc" -I"/home/pablo/Documents/CIAA-Repositories/EOPT/workspace/CMSIS_LPC43xx_DriverLib/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/cr_startup_lpc43xx.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


