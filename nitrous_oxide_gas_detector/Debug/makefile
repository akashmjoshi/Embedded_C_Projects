################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)

ORDERED_OBJS += \
$(GEN_CMDS_QUOTED) \
"./port_setup.obj" \
"./main.obj" \
"./logic.obj" \
"./keysensing.obj" \
"./gas_calculation.obj" \
"./eeprom_SPI.obj" \
"./display.obj" \
"./decode_slave.obj" \
"./decode_master.obj" \
"./Uart_Init_1.obj" \
"./Uart_Init.obj" \
"./TIMER_B.obj" \
"./TIMER_A.obj" \
"./Send_Request.obj" \
"./SPI_Setup.obj" \
"./LCD.obj" \
"./IR_REMOTE.obj" \
"./DAC.obj" \
-l"rts430xl.lib" \
"../lnk_msp430f2618.cmd" \

-include ../makefile.init

RM := DEL /F

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: GM-6611.out

# Tool invocations
GM-6611.out: $(GEN_CMDS) $(CMD_SRCS) $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --diag_warning=225 --printf_support=minimal -z -m"GM-6611.map" --stack_size=80 --heap_size=80 --use_hw_mpy=16 --warn_sections -i"C:/Program Files/Texas Instruments/ccsv4/msp430/include" -i"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/lib" -i"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" -i"C:/Program Files/Texas Instruments/ccsv4/msp430/include" --reread_libs --rom_model -o "GM-6611.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(MSP430_EXECUTABLE_OUTPUTS__QTD) "GM-6611.out"
	-$(RM) ".\DAC.obj" ".\IR_REMOTE.obj" ".\LCD.obj" ".\SPI_Setup.obj" ".\Send_Request.obj" ".\TIMER_A.obj" ".\TIMER_B.obj" ".\Uart_Init.obj" ".\Uart_Init_1.obj" ".\decode_master.obj" ".\decode_slave.obj" ".\display.obj" ".\eeprom_SPI.obj" ".\gas_calculation.obj" ".\keysensing.obj" ".\logic.obj" ".\main.obj" ".\port_setup.obj" 
	-$(RM) ".\DAC.pp" ".\IR_REMOTE.pp" ".\LCD.pp" ".\SPI_Setup.pp" ".\Send_Request.pp" ".\TIMER_A.pp" ".\TIMER_B.pp" ".\Uart_Init.pp" ".\Uart_Init_1.pp" ".\decode_master.pp" ".\decode_slave.pp" ".\display.pp" ".\eeprom_SPI.pp" ".\gas_calculation.pp" ".\keysensing.pp" ".\logic.pp" ".\main.pp" ".\port_setup.pp" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
