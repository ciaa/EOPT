################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ActivateTask.c \
../src/CancelAlarm.c \
../src/ChainTask.c \
../src/ClearEvent.c \
../src/GetActiveApplicationMode.c \
../src/GetAlarm.c \
../src/GetAlarmBase.c \
../src/GetEvent.c \
../src/GetResource.c \
../src/GetTaskID.c \
../src/GetTaskState.c \
../src/Os.c \
../src/Os_Arch.c \
../src/Os_Cfg.c \
../src/Os_Internal.c \
../src/Os_Internal_Arch.c \
../src/Os_Internal_Cfg.c \
../src/ReleaseResource.c \
../src/Schedule.c \
../src/SetAbsAlarm.c \
../src/SetEvent.c \
../src/SetRelAlarm.c \
../src/ShutdownOS.c \
../src/StartOS.c \
../src/StartOs_Arch.c \
../src/TerminateTask.c \
../src/WaitEvent.c \
../src/blinking.c \
../src/ciaaIO.c \
../src/ciaaUART.c \
../src/cr_startup_lpc43xx.c \
../src/crp.c 

S_SRCS += \
../src/PendSV.s 

OBJS += \
./src/ActivateTask.o \
./src/CancelAlarm.o \
./src/ChainTask.o \
./src/ClearEvent.o \
./src/GetActiveApplicationMode.o \
./src/GetAlarm.o \
./src/GetAlarmBase.o \
./src/GetEvent.o \
./src/GetResource.o \
./src/GetTaskID.o \
./src/GetTaskState.o \
./src/Os.o \
./src/Os_Arch.o \
./src/Os_Cfg.o \
./src/Os_Internal.o \
./src/Os_Internal_Arch.o \
./src/Os_Internal_Cfg.o \
./src/PendSV.o \
./src/ReleaseResource.o \
./src/Schedule.o \
./src/SetAbsAlarm.o \
./src/SetEvent.o \
./src/SetRelAlarm.o \
./src/ShutdownOS.o \
./src/StartOS.o \
./src/StartOs_Arch.o \
./src/TerminateTask.o \
./src/WaitEvent.o \
./src/blinking.o \
./src/ciaaIO.o \
./src/ciaaUART.o \
./src/cr_startup_lpc43xx.o \
./src/crp.o 

C_DEPS += \
./src/ActivateTask.d \
./src/CancelAlarm.d \
./src/ChainTask.d \
./src/ClearEvent.d \
./src/GetActiveApplicationMode.d \
./src/GetAlarm.d \
./src/GetAlarmBase.d \
./src/GetEvent.d \
./src/GetResource.d \
./src/GetTaskID.d \
./src/GetTaskState.d \
./src/Os.d \
./src/Os_Arch.d \
./src/Os_Cfg.d \
./src/Os_Internal.d \
./src/Os_Internal_Arch.d \
./src/Os_Internal_Cfg.d \
./src/ReleaseResource.d \
./src/Schedule.d \
./src/SetAbsAlarm.d \
./src/SetEvent.d \
./src/SetRelAlarm.d \
./src/ShutdownOS.d \
./src/StartOS.d \
./src/StartOs_Arch.d \
./src/TerminateTask.d \
./src/WaitEvent.d \
./src/blinking.d \
./src/ciaaIO.d \
./src/ciaaUART.d \
./src/cr_startup_lpc43xx.d \
./src/crp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU=lpc4337 -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_CMSIS=CMSIS_LPC43xx_DriverLib -D__LPC43XX__ -D__MULTICORE_NONE -I"/home/pablo/Dropbox/Privado/Electrónica/NXP/LPC43xx/workspace/LPC4330_Xplorer_UsbVcomLib/inc" -I"/home/pablo/Documents/CIAA-Repositories/EOPT/workspace/CMSIS_LPC43xx_DriverLib/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__REDLIB__ -DDEBUG -D__CODE_RED -D__MULTICORE_NONE -g3 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


