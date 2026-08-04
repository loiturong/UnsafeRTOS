set(target Port)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC 
	${DIR}/port.c
	${DIR}/exception.c
	${DIR}/vector_table.s
)

add_library(${target} OBJECT ${SRC})
target_link_libraries(${target} PRIVATE general_flags)
target_include_directories(${target} PRIVATE
	${DIR}/Include
	${DIR}/CMSIS/Include
	${DIR}/CMSIS/DeviceHeader
)

target_compile_options(${target} PRIVATE
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
	# Check for missing headers, to check for prototype mismatch
	-Wmissing-prototypes
)

