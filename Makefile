# Toolchain
PREFIX  := arm-none-eabi-
CC      := $(PREFIX)gcc
AS      := $(PREFIX)gcc -x assembler-with-cpp
CP      := $(PREFIX)objcopy
SZ      := $(PREFIX)size

# Build Directory
BDIR	:= build

# Target
TAR		:= rtos
# Alias for STM family
ALIAS	:= STM32F4xx
# BOARD
BOARD	:= STM32F411xE

# MCU Flags
CPU     := -mcpu=cortex-m4
# FPU
FPU 	= -mfpu=fpv4-sp-d16
# FLOAT-ABI
FLOAT-ABI = -mfloat-abi=hard
# MCU
MCU		:= $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# C Defines
C_DEFS  := -D$(BOARD) -DUSE_HAL_DRIVER

# C Includes
C_INCLUDES := \
-ICore/Inc \
-IDrivers/$(ALIAS)_HAL_Driver/Inc \
-IDrivers/$(ALIAS)_HAL_Driver/Inc/Legacy \
-IDrivers/CMSIS/Device/ST/$(ALIAS)/Include \
-IDrivers/CMSIS/Include

# Compile Flags
CFLAGS  := $(MCU) $(C_DEFS) $(C_INCLUDES) \
		   -Og -Wall -fdata-sections -ffunction-sections \
		   -g -gdwarf-2 -std=gnu11 -fno-common -fmessage-length=0 \
		   -MMD -MP

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 

# Sources file
SOURCES_C := $(wildcard Core/Src/*.c) \
			 $(wildcard Drivers/$(ALIAS)_HAL_Driver/Src/*.c)

SOURCES_S := $(wildcard Core/Startup/*.s) \
			 $(wildcard *.s)

# Object file
OBJS := $(patsubst %.c, $(BDIR)/%.o, $(SOURCES_C)) \
		$(patsubst %.s, $(BDIR)/%.o, $(SOURCES_S))

# Linker Flags
LDSCRIPT := STM32F411XX_FLASH.ld
LDFLAGS  := $(MCU) -specs=nano.specs -T$(LDSCRIPT) \
			$(LIBDIR) $(LIBS) \
			-Wl,-Map=$(BDIR)/output.map -Wl,--gc-sections \
			-Wl,--print-memory-usage 

.PHONY: all clean flash debug

all: $(BDIR)/$(TAR).bin $(BDIR)/$(TAR).elf
	$(SZ) $(BDIR)/$(TAR).elf
	
debug: C_DEFS += -DDEBUG
debug: all

$(BDIR)/$(TAR).elf: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

$(BDIR)/%.bin: $(BDIR)/%.elf
	$(CP) -O binary -S $< $@

$(BDIR)/%.o: %.c
	@echo "Compiling $<"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BDIR)/%.o: %.s
	@echo "Assembling $<"
	@mkdir -p $(dir $@)
	$(AS) -c $< -o $@

clean:
	rm -rf $(BDIR)

flash: all
	st-flash write $(BDIR)/$(TAR).bin 0x8000000

-include $(OBJS:.o=.d)
