cmake_minimum_required(VERSION 4.0)

# Toolchain
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm-none-eabi)
set(CMAKE_C_COMPILER   arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
# Post build tools
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(CMAKE_NM arm-none-eabi-nm)

# Build type and optimization flag
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    set(OPT -O2)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    set(OPT -O2 -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    set(OPT -Os)
else ()
    set(OPT -Og -g3 -gdwarf -fno-omit-frame-pointer)
    #set(AS_OPT -Og -g -gdwarf-5 -fno-omit-frame-pointer)
endif ()
message(STATUS "System build type is: ${CMAKE_BUILD_TYPE}")

set(CMAKE_ASM_FLAGS_RELEASE "")
set(CMAKE_ASM_FLAGS_DEBUG "")
set(CMAKE_ASM_FLAGS_RELWITHDEBINFO "")
set(CMAKE_ASM_FLAGS_MINSIZEREL "")

set(CMAKE_C_FLAGS_RELEASE "")
set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "")
set(CMAKE_C_FLAGS_MINSIZEREL "")

# project settings
project(rtos C ASM)
set(CMAKE_C_STANDARD 11)

# Manual control over source files
set(DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE_FILES
	${DIR}/startup.s
	${DIR}/kernel/kernel.c
)
set(LINKER_SCRIPT ${DIR}/linker.ld)

add_subdirectory(drivers/HAL_stm32f4xx)

add_executable(${PROJECT_NAME} 
	${SOURCE_FILES}
	$<TARGET_OBJECTS:hal>
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
	ARM_MATH_CM4
	ARM_MATH_MATRIX_CHECK
	ARM_MATH_ROUNDING
	-DDEBUG 
	-DUSE_HAL_DRIVER 
	-DSTM32F411xE
)

target_compile_options(${PROJECT_NAME} PRIVATE
	-mcpu=cortex-m4 -mthumb -mthumb-interwork
	-mfloat-abi=hard -mfpu=fpv4-sp-d16
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
)

target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_SOURCE_DIR}/
)

target_link_options(${PROJECT_NAME} PRIVATE
	-mcpu=cortex-m4 -mthumb -mthumb-interwork
	-mfloat-abi=hard -mfpu=fpv4-sp-d16
	-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map
	-T ${LINKER_SCRIPT}
)

# Build binary for the board
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)
add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}> ${BIN_FILE}
        COMMENT "Building ${BIN_FILE}"
)

# Debug
add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_OBJDUMP} -D -S $<TARGET_FILE:${PROJECT_NAME}> > $<TARGET_FILE:${PROJECT_NAME}>.asm
	COMMAND ${CMAKE_OBJDUMP} -h $<TARGET_FILE:${PROJECT_NAME}> > $<TARGET_FILE:${PROJECT_NAME}>.sections
	COMMAND ${CMAKE_NM} -n -S $<TARGET_FILE:${PROJECT_NAME}> > $<TARGET_FILE:${PROJECT_NAME}>.sym
	COMMENT "Adding debug information for ${PROJECT_NAME}"
)
