################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: CIAA-Demo-M0.axf

# Tool invocations
CIAA-Demo-M0.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/pablo/Dropbox/Privado/FRBA/DPLab/osek_lpc4337/CMSIS_LPC43xx_DriverLib-M0/Debug" -L"/home/pablo/Dropbox/Privado/FRBA/DPLab/osek_lpc4337/CMSIS_DSPLIB_CM0/lib" -Xlinker -Map="CIAA-Demo-M0.map" -Xlinker --gc-sections -mcpu=cortex-m0 -mthumb -T "CIAA-Demo-M0_Debug.ld" -o "CIAA-Demo-M0.axf" $(OBJS) $(USER_OBJS) $(LIBS) && arm-none-eabi-objcopy --target elf32-littlearm --verbose --strip-all --redefine-sym __vectors_start__=__vectors_start___core_m0app --keep-symbol __vectors_start___core_m0app --rename-section .text=".core_m0app" --rename-section .data=".core_m0app.data" "CIAA-Demo-M0.axf" "CIAA-Demo-M0.axf.o"
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) CIAA-Demo-M0.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "CIAA-Demo-M0.axf"; # arm-none-eabi-objcopy -v -O binary "CIAA-Demo-M0.axf" "CIAA-Demo-M0.bin" ; # checksum -p LPC4337_M0 -d "CIAA-Demo-M0.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
