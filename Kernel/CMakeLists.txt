set(target Kernel)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC 
	${DIR}/kernel.c
	${DIR}/scheduler/task.c
	${DIR}/scheduler/scheduler.c
	${DIR}/ds/stack.c
	${DIR}/heap/heap.c

)

add_library(${target} OBJECT ${SRC})
target_link_libraries(${target} PRIVATE)
target_include_directories(${target} PRIVATE
	${CMAKE_SOURCE_DIR}/
	${DIR}/
)

target_link_libraries(${target} PRIVATE General_Settings)
