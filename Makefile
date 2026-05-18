# Toolchain
PREFIX  := arm-none-eabi-
CC      := $(PREFIX)gcc
AS      := $(PREFIX)gcc -x assembler-with-cpp
CP      := $(PREFIX)objcopy
SZ      := $(PREFIX)size

# Build Directory
BDIR	:= build
RDIR	:= $(BDIR)/release
DDIR	:= $(BDIR)/debug


#################################
#		TARGET SPECIFIC			#
#################################

# Target Name
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


#################################
#		TOOLCHAIN FLAG			#
#################################

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
		   -Wall -Wconversion -Wcast-qual \
		   -fdata-sections -ffunction-sections \
		   -std=gnu11 -fno-common -fmessage-length=0 \
		   -MMD -MP
RFLAGS	:= -O2
DFLAGS	:= -Og -g3 -ggdb -gdwarf-2
# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
# Linker Flags
LDSCRIPT := STM32F411XX_FLASH.ld
LDFLAGS  := $(MCU) -specs=nano.specs -T$(LDSCRIPT) \
			$(LIBDIR) $(LIBS)

RMAP	:= -Wl,-Map=$(RDIR)/$(TAR).map -Wl,--gc-section -Wl,--print-memory-usage
DMAP	:= -Wl,-Map=$(DDIR)/$(TAR).map -Wl,--gc-section -Wl,--print-memory-usage


#################################
#		SOURCE AND TARGET		#
#################################

# Sources file
SOURCES_C := $(wildcard Core/Src/*.c) \
			 $(wildcard Drivers/$(ALIAS)_HAL_Driver/Src/*.c)
SOURCES_S := $(wildcard *.s) \
			 $(wildcard Core/Startup/*.s)

# Object file
ROBJS 	:= $(patsubst %.c, $(RDIR)/%.o, $(SOURCES_C)) \
		   $(patsubst %.s, $(RDIR)/%.o, $(SOURCES_S))
DOBJS 	:= $(patsubst %.c, $(DDIR)/%.o, $(SOURCES_C)) \
		   $(patsubst %.s, $(DDIR)/%.o, $(SOURCES_S))

#################################
#			BUILD RULES			#
#################################

.PHONY: all clean release debug openocd gdb
.PHONY: flash-release flash-debug
.PHONY: Makefile

all: release

clean:
	rm -rf $(BDIR)

release: $(ROBJS)
	$(CC) $(ROBJS) $(LDFLAGS) $(RMAP) -o $(RDIR)/$(TAR).elf
	$(CP) -O binary -S $(RDIR)/$(TAR).elf $(RDIR)/$(TAR).bin
	$(SZ) $(RDIR)/$(TAR).elf

debug: C_DEFS += -DDEBUG
debug: $(DOBJS)
	$(CC) $(DOBJS) $(LDFLAGS) $(DMAP) -o $(DDIR)/$(TAR).elf
	$(CP) -O binary -S $(DDIR)/$(TAR).elf $(DDIR)/$(TAR).bin
	$(SZ) $(DDIR)/$(TAR).elf

openocd:
	openocd -f openocd.cfg

gdb:
	arm-none-eabi-gdb $(DDIR)/$(TAR).elf

flash-release:
	st-flash write $(RDIR)/$(TAR).bin 0x08000000

flash-debug:
	st-flash write $(DDIR)/$(TAR).bin 0x08000000

$(RDIR)/%.o: %.c
	@echo "Compiling $<"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(RFLAGS) -c $< -o $@

$(RDIR)/%.o: %.s
	@echo "Assembling $<"
	@mkdir -p $(dir $@)
	$(AS) $(CFLAGS) $(RFLAGS) -c $< -o $@

$(DDIR)/%.o: %.c
	@echo "Compiling $<"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

$(DDIR)/%.o: %.s
	@echo "Assembling $<"
	@mkdir -p $(dir $@)
	$(AS) $(CFLAGS) $(DFLAGS) -c $< -o $@

-include $(ROBJS:.o=.d)
-include $(DOBJS:.o=.d)
