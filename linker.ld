ENTRY(reset_handler)

MEMORY
{
	RAM (xrw)	: ORIGIN = 0x20000000, LENGTH = 128K
	FLASH (rx)	: ORIGIN = 0x08000000, LENGTH = 512K
}

/* Stack size for system and user */
SSTACK_SIZE = 0x10000;

/* Stack placement */
_sstack_top = ORIGIN(RAM) + LENGTH(RAM);
_ustack_top = _sstack_bottom = _sstack_top - SSTACK_SIZE;
