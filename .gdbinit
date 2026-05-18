# Define utility macros
define rst
    monitor reset halt
end

define regs
    info registers
end

define getmem
    x/16wx $arg0
end

define btf
    backtrace full
end

set pagination off
set confirm off
set print pretty on
set disassemble-next-line on

# Better ARM stepping behavior
set mem inaccessible-by-default off

# Connect to OpenOCD
target extended-remote localhost:3333

# Reset + halt MCU
monitor reset halt

# Not Flash the firmware constantly, prevent Flash worm out

# Skip some library function
skip function memset
skip function memcpy
skip function memmove
skip function __aeabi_memclr
skip function __libc_init_array

# Stop at main(), which will pass control to kernel
break main
continue

