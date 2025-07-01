################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := BAREMETAL_PORTA_ODD_EVEN
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
BAREMETAL_PORTA_ODD_EVEN.elf \

MAP_FILES += \
BAREMETAL_PORTA_ODD_EVEN.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
BAREMETAL_PORTA_ODD_EVEN.list \


# All Target
all: main-build

# Main-build Target
main-build: BAREMETAL_PORTA_ODD_EVEN.elf secondary-outputs

# Tool invocations
BAREMETAL_PORTA_ODD_EVEN.elf BAREMETAL_PORTA_ODD_EVEN.map: $(OBJS) $(USER_OBJS) /home/sl/STM32CubeIDE/workspace_1.18.1/BAREMETAL_PORTA_ODD_EVEN/STM32F401CCUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "BAREMETAL_PORTA_ODD_EVEN.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/sl/STM32CubeIDE/workspace_1.18.1/BAREMETAL_PORTA_ODD_EVEN/STM32F401CCUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="BAREMETAL_PORTA_ODD_EVEN.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

BAREMETAL_PORTA_ODD_EVEN.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "BAREMETAL_PORTA_ODD_EVEN.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) BAREMETAL_PORTA_ODD_EVEN.elf BAREMETAL_PORTA_ODD_EVEN.list BAREMETAL_PORTA_ODD_EVEN.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
