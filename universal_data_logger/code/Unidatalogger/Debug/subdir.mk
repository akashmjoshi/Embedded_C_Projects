################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD.c \
../RTC.c \
../TI_USCI_I2C_master.c \
../UART.c \
../Unidatalogger.c \
../adc.c \
../display(new).c \
../port_setup.c \
../shift_data.c 

CMD_SRCS += \
../lnk_msp430f2618.cmd 

OBJS += \
./LCD.obj \
./RTC.obj \
./TI_USCI_I2C_master.obj \
./UART.obj \
./Unidatalogger.obj \
./adc.obj \
./display(new).obj \
./port_setup.obj \
./shift_data.obj 

C_DEPS += \
./LCD.pp \
./RTC.pp \
./TI_USCI_I2C_master.pp \
./UART.pp \
./Unidatalogger.pp \
./adc.pp \
./display(new).pp \
./port_setup.pp \
./shift_data.pp 

OBJS__QTD += \
".\LCD.obj" \
".\RTC.obj" \
".\TI_USCI_I2C_master.obj" \
".\UART.obj" \
".\Unidatalogger.obj" \
".\adc.obj" \
".\display(new).obj" \
".\port_setup.obj" \
".\shift_data.obj" 

C_DEPS__QTD += \
".\LCD.pp" \
".\RTC.pp" \
".\TI_USCI_I2C_master.pp" \
".\UART.pp" \
".\Unidatalogger.pp" \
".\adc.pp" \
".\display(new).pp" \
".\port_setup.pp" \
".\shift_data.pp" 

C_SRCS_QUOTED += \
"../LCD.c" \
"../RTC.c" \
"../TI_USCI_I2C_master.c" \
"../UART.c" \
"../Unidatalogger.c" \
"../adc.c" \
"../display(new).c" \
"../port_setup.c" \
"../shift_data.c" 


# Each subdirectory must supply rules for building sources it contributes
LCD.obj: ../LCD.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430F2618__ --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="LCD.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

RTC.obj: ../RTC.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430F2618__ --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="RTC.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

TI_USCI_I2C_master.obj: ../TI_USCI_I2C_master.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430F2618__ --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="TI_USCI_I2C_master.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

UART.obj: ../UART.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430F2618__ --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="UART.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Unidatalogger.obj: ../Unidatalogger.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430F2618__ --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="Unidatalogger.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

adc.obj: ../adc.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430F2618__ --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="adc.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

display(new).obj: ../display(new).c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430F2618__ --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="display(new).pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

port_setup.obj: ../port_setup.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430F2618__ --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="port_setup.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

shift_data.obj: ../shift_data.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx -g --define=__MSP430F2618__ --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="shift_data.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


