ENTRY(reset_handler)

MEMORY
{
	RAM   (xrw)	: ORIGIN = 0x20000000, LENGTH = 128K
	FLASH (rx)	: ORIGIN = 0x08000000, LENGTH = 512K
}

/* Stack size for system and user */
SSTACK_SIZE = 0x10000;

/* Stack placement */
_sstack_top = ORIGIN(RAM) + LENGTH(RAM);
_sstack_bottom = _sstack_top - SSTACK_SIZE;
_ustack_top = _sstack_bottom;

SECTIONS
{	
	. = ORIGIN(FLASH);
	/* Place Startup code */
	.startup ALIGN(4) :
  	{
    		KEEP(*(.hardware_startup))
		. = ALIGN(4);
  	}>FLASH

	.text ALIGN(4) :
	{
		KEEP(*(.bootloader))
		*(.text)
		*(.text.*)	/* Use of function-section */
		. = ALIGN(4);
	}>FLASH

	.rodata ALIGN(4) :
	{
		*(.rodata.*)
	}>FLASH

	.data ALIGN(4) :
	{
		*(.data.*)
	}>RAM AT>FLASH

	.bss ALIGN(4) :
	{
		*(.bss.*)
    		. = ALIGN(4);
	}>RAM
}
