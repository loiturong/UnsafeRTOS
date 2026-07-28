ENTRY(Reset_Handler)

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
	.isr_vector ALIGN(4) :
  	{
    		KEEP(*(.interrupt_vector_table))
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

	/* Below Sections are using RAM memory region */
	. = ORIGIN(RAM);
	.data ALIGN(4) :
	{
		data_start = .;
		*(.data.*)
	}>RAM AT>FLASH

	.bss ALIGN(4) :
	{
		bss_load_start = .;
		*(.bss.*)
    		. = ALIGN(4);
	}>RAM

	/* Compute data length */
	data_size = SIZEOF(.data);
	data_load_start = LOADADDR(.data);
	bss_size = SIZEOF(.bss);
}
