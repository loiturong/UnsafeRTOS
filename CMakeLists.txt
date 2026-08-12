cmake_minimum_required(VERSION 4.0)
project(rtos_kernel C ASM)

add_library(${PROJECT_NAME} STATIC
    exception.c
    heap.c
    port.c
    scheduler.c
    stack.c
    task.c
    exception.s
)

target_include_directories(${PROJECT_NAME}
    	PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Include
        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS/Include
	${CMAKE_CURRENT_SOURCE_DIR}/CMSIS/DeviceHeader
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
