################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DAC.c \
../IR_REMOTE.c \
../LCD.c \
../SPI_Setup.c \
../Send_Request.c \
../TIMER_A.c \
../TIMER_B.c \
../Uart_Init.c \
../Uart_Init_1.c \
../decode_master.c \
../decode_slave.c \
../display.c \
../eeprom_SPI.c \
../gas_calculation.c \
../keysensing.c \
../logic.c \
../main.c \
../port_setup.c 

CMD_SRCS += \
../lnk_msp430f2618.cmd 

OBJS += \
./DAC.obj \
./IR_REMOTE.obj \
./LCD.obj \
./SPI_Setup.obj \
./Send_Request.obj \
./TIMER_A.obj \
./TIMER_B.obj \
./Uart_Init.obj \
./Uart_Init_1.obj \
./decode_master.obj \
./decode_slave.obj \
./display.obj \
./eeprom_SPI.obj \
./gas_calculation.obj \
./keysensing.obj \
./logic.obj \
./main.obj \
./port_setup.obj 

C_DEPS += \
./DAC.pp \
./IR_REMOTE.pp \
./LCD.pp \
./SPI_Setup.pp \
./Send_Request.pp \
./TIMER_A.pp \
./TIMER_B.pp \
./Uart_Init.pp \
./Uart_Init_1.pp \
./decode_master.pp \
./decode_slave.pp \
./display.pp \
./eeprom_SPI.pp \
./gas_calculation.pp \
./keysensing.pp \
./logic.pp \
./main.pp \
./port_setup.pp 

OBJS__QTD += \
".\DAC.obj" \
".\IR_REMOTE.obj" \
".\LCD.obj" \
".\SPI_Setup.obj" \
".\Send_Request.obj" \
".\TIMER_A.obj" \
".\TIMER_B.obj" \
".\Uart_Init.obj" \
".\Uart_Init_1.obj" \
".\decode_master.obj" \
".\decode_slave.obj" \
".\display.obj" \
".\eeprom_SPI.obj" \
".\gas_calculation.obj" \
".\keysensing.obj" \
".\logic.obj" \
".\main.obj" \
".\port_setup.obj" 

C_DEPS__QTD += \
".\DAC.pp" \
".\IR_REMOTE.pp" \
".\LCD.pp" \
".\SPI_Setup.pp" \
".\Send_Request.pp" \
".\TIMER_A.pp" \
".\TIMER_B.pp" \
".\Uart_Init.pp" \
".\Uart_Init_1.pp" \
".\decode_master.pp" \
".\decode_slave.pp" \
".\display.pp" \
".\eeprom_SPI.pp" \
".\gas_calculation.pp" \
".\keysensing.pp" \
".\logic.pp" \
".\main.pp" \
".\port_setup.pp" 

C_SRCS_QUOTED += \
"../DAC.c" \
"../IR_REMOTE.c" \
"../LCD.c" \
"../SPI_Setup.c" \
"../Send_Request.c" \
"../TIMER_A.c" \
"../TIMER_B.c" \
"../Uart_Init.c" \
"../Uart_Init_1.c" \
"../decode_master.c" \
"../decode_slave.c" \
"../display.c" \
"../eeprom_SPI.c" \
"../gas_calculation.c" \
"../keysensing.c" \
"../logic.c" \
"../main.c" \
"../port_setup.c" 


# Each subdirectory must supply rules for building sources it contributes
DAC.obj: ../DAC.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="DAC.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

IR_REMOTE.obj: ../IR_REMOTE.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="IR_REMOTE.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

LCD.obj: ../LCD.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="LCD.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

SPI_Setup.obj: ../SPI_Setup.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="SPI_Setup.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Send_Request.obj: ../Send_Request.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="Send_Request.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

TIMER_A.obj: ../TIMER_A.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="TIMER_A.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

TIMER_B.obj: ../TIMER_B.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="TIMER_B.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Uart_Init.obj: ../Uart_Init.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="Uart_Init.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Uart_Init_1.obj: ../Uart_Init_1.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="Uart_Init_1.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

decode_master.obj: ../decode_master.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="decode_master.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

decode_slave.obj: ../decode_slave.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="decode_slave.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

display.obj: ../display.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="display.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

eeprom_SPI.obj: ../eeprom_SPI.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="eeprom_SPI.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

gas_calculation.obj: ../gas_calculation.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="gas_calculation.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

keysensing.obj: ../keysensing.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="keysensing.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

logic.obj: ../logic.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="logic.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

port_setup.obj: ../port_setup.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/bin/cl430" -vmspx --large_memory_model -g --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="port_setup.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


