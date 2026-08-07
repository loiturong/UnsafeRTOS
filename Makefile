.PHONY: emu gdb

emu	:= qemu-system-arm
gdb 	:= arm-none-eabi-gdb
base	:= $(CURDIR)/build/rtos
elf	:= $(base)
bin	:= $(base).bin

emu:
	$(emu) -M olimex-stm32-h405 \
	-kernel $(bin) \
	-S -gdb tcp::3333

gdb:
	$(gdb) $(elf)

