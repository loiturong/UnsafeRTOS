cmake_minimum_required(VERSION 4.0)
project(rtos_kernel C ASM)

# TODO: check for ARCH included
set(ARCH M4)
add_library(${PROJECT_NAME} STATIC
    heap.c
    scheduler.c
    stack.c
    task.c
    syscall.c
    Arch/${ARCH}/port.c
    Arch/${ARCH}/exception.c
    Arch/${ARCH}/exception.s
    Arch/${ARCH}/syscall.s
)

target_include_directories(${PROJECT_NAME}
    	PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Include
	${CMAKE_CURRENT_SOURCE_DIR}/Arch/${ARCH}/Include
)

set_source_files_properties(
	exception.s
	PROPERTIES LANGUAGE ASM
)

# TODO: Find a way to tell application to include this
if(NOT BOARD_FLAGS)
	set(BOARD_FLAGS
		-mcpu=cortex-m4 -mthumb -mthumb-interwork
		-mfloat-abi=hard -mfpu=fpv4-sp-d16
	)
endif()

if(NOT OPT)
	set(OPT -Og -g3 -gdwarf -fno-omit-frame-pointer)
endif()

target_compile_options(${PROJECT_NAME} 
	PRIVATE
	${BOARD_FLAGS}
	# Warning flags
	-Wall -Werror -Wextra
	-Wshadow -Wdouble-promotion
	-Wcast-qual -Wformat=2
	# Optimize
	${OPT}
	-ffunction-sections -fdata-sections  -fmessage-length=0
	-fno-common -MMD -MP
	-fno-pic -fno-pie
	-ffreestanding -fno-builtin 
	-fno-strict-aliasing -fno-stack-protector
	# No unaligned access
	-mno-unaligned-access
	# Check for missing headers, to check for prototype mismatch
	-Wmissing-prototypes
)
