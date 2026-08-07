set(target HAL)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC 
	${DIR}/hal.c
	${DIR}/hal_rcc.c
	${DIR}/vector_table.s
)

add_library(${target} OBJECT ${SRC})
target_link_libraries(${target} PRIVATE general_flags)
target_include_directories(${target} PRIVATE
	${DIR}/Include
)

target_link_libraries(${target} PRIVATE General_Settings)

target_compile_options(${target} PRIVATE
	# Check for missing headers, to check for prototype mismatch
	-Wmissing-prototypes
)

