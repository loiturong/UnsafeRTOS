set(target Port)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC 
	${DIR}/port.c
	${DIR}/exception.c
	${DIR}/exception.s
	${DIR}/vector_table.s
)

add_library(${target} OBJECT ${SRC})
target_link_libraries(${target} PRIVATE)
target_include_directories(${target} PRIVATE
	${DIR}/Include
	${DIR}/CMSIS/Include
	${DIR}/CMSIS/DeviceHeader
)

target_link_libraries(${target} PRIVATE General_Settings)

target_compile_options(${target} PRIVATE
	# Check for missing headers, to check for prototype mismatch
	-Wmissing-prototypes
)
