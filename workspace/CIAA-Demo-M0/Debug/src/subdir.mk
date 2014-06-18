################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc43xx-m0app.c \
../src/main_m0.c 

OBJS += \
./src/cr_startup_lpc43xx-m0app.o \
./src/main_m0.o 

C_DEPS += \
./src/cr_startup_lpc43xx-m0app.d \
./src/main_m0.d 


# Each subdirectory must supply rules for building sources it contributes
src/cr_startup_lpc43xx-m0app.o: ../src/cr_startup_lpc43xx-m0app.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M0 -D__USE_CMSIS=CMSIS_LPC43xx_DriverLib-M0 -D__USE_CMSIS_DSPLIB=CMSIS_DSPLIB_CM0 -D__LPC43XX__ -DCORE_M0APP -D__MULTICORE_M0APP -I"/home/pablo/Dropbox/Privado/FRBA/DPLab/osek_lpc4337/CMSIS_LPC43xx_DriverLib-M0/inc" -I"/home/pablo/Dropbox/Privado/FRBA/DPLab/osek_lpc4337/CMSIS_DSPLIB_CM0/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/cr_startup_lpc43xx-m0app.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M0 -D__USE_CMSIS=CMSIS_LPC43xx_DriverLib-M0 -D__USE_CMSIS_DSPLIB=CMSIS_DSPLIB_CM0 -D__LPC43XX__ -DCORE_M0APP -D__MULTICORE_M0APP -I"/home/pablo/Dropbox/Privado/FRBA/DPLab/osek_lpc4337/CMSIS_LPC43xx_DriverLib-M0/inc" -I"/home/pablo/Dropbox/Privado/FRBA/DPLab/osek_lpc4337/CMSIS_DSPLIB_CM0/inc" -Og -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


