ENTRY(reset_handler)

MEMORY
{
	RAM   (xrw)	: ORIGIN = 0x20000000, LENGTH = 128K
	FLASH (rx)	: ORIGIN = 0x08000000, LENGTH = 512K
}

PHDRS
{
	HW_SPC	PT_LOAD FLAGS(4);
	CODE	PT_LOAD FLAGS(6);
	RODATA	PT_LOAD FLAGS(4);
	DATA	PT_LOAD FLAGS(5);
	DEBUG	PT_NULL;
	PROC	PT_NOTE;
}

/* Stack size for system and user */
SSTACK_SIZE = 0x10000;

/* Stack placement */
_sstack_top = ORIGIN(RAM) + LENGTH(RAM);
_sstack_bottom = _sstack_top - SSTACK_SIZE;
_ustack_top = _sstack_bottom;

SECTIONS
{
	/* Place Startup code */
	.startup ALIGN(4) :
  	{
    		KEEP(*(.hardware_startup))
  	}>FLASH : HW_SPC

	.text ALIGN(4) :
	{
		*(.bootloader)
		*(.text.*)	/* Use of function-section */
	}>FLASH : CODE

	.rodata ALIGN(4) :
	{
		*(.rodata.*)
	}>RAM AT>FLASH : RODATA

	.data ALIGN(4) :
	{
		*(.data.*)
	}>RAM AT>FLASH : DATA

	.bss ALIGN(4) :
	{
		*(.bss.*)
    		. = ALIGN(4);
	}>RAM : DATA
}
