cmake_minimum_required (VERSION 2.6)
project(square_and_add)
add_subdirectory(libsrc)
add_subdirectory(src)
add_subdirectory(libs)
add_custom_command(
	OUTPUT ${PROJECT_SOURCE_DIR}/build/sqnadd_no_lib
	COMMAND cp ${PROJECT_SOURCE_DIR}/build/src/sqnadd_no_lib ${PROJECT_SOURCE_DIR}/build/sqnadd_no_lib
	DEPENDS ${PROJECT_SOURCE_DIR}/build/src/sqnadd_no_lib
)
add_custom_target(no_lib_exec
	DEPENDS ${PROJECT_SOURCE_DIR}/build/sqnadd_no_lib
)

add_custom_command(
	OUTPUT ${PROJECT_SOURCE_DIR}/build/static_library.a
	COMMAND cp ${PROJECT_SOURCE_DIR}/build/libsrc/src/libstatic_library.a ${PROJECT_SOURCE_DIR}/build/static_library.a
	DEPENDS ${PROJECT_SOURCE_DIR}/build/libsrc/src/libstatic_library.a
)
add_custom_target(build_static_lib
	DEPENDS ${PROJECT_SOURCE_DIR}/build/static_library.a
)

add_custom_command(
	OUTPUT ${PROJECT_SOURCE_DIR}/build/sqnadd_stat_lib
	COMMAND cp ${PROJECT_SOURCE_DIR}/build/src/sqnadd_stat_lib ${PROJECT_SOURCE_DIR}/build/sqnadd_stat_lib
	DEPENDS ${PROJECT_SOURCE_DIR}/build/src/sqnadd_stat_lib
)
add_custom_target(static_lib_exec
	DEPENDS ${PROJECT_SOURCE_DIR}/build/sqnadd_stat_lib
)

add_custom_command(
	OUTPUT ${PROJECT_SOURCE_DIR}/build/dynamic_library.so
	COMMAND cp ${PROJECT_SOURCE_DIR}/build/libsrc/src/libdynamic_library.so ${PROJECT_SOURCE_DIR}/build/dynamic_library.so
	DEPENDS ${PROJECT_SOURCE_DIR}/build/libsrc/src/libdynamic_library.so
)
add_custom_target(build_dynamic_lib
	DEPENDS ${PROJECT_SOURCE_DIR}/build/dynamic_library.so
)

add_custom_command(
	OUTPUT ${PROJECT_SOURCE_DIR}/build/sqnadd_dyn_lib
	COMMAND cp ${PROJECT_SOURCE_DIR}/build/src/sqnadd_dyn_lib ${PROJECT_SOURCE_DIR}/build/sqnadd_dyn_lib
	DEPENDS ${PROJECT_SOURCE_DIR}/build/src/sqnadd_dyn_lib
)
add_custom_target(dynamic_lib_exec
	DEPENDS ${PROJECT_SOURCE_DIR}/build/sqnadd_dyn_lib
)

add_custom_command(
	OUTPUT ${PROJECT_SOURCE_DIR}/libs/dynamic_library.so
	OUTPUT ${PROJECT_SOURCE_DIR}/libs/static_library.a	
	COMMAND cp ${PROJECT_SOURCE_DIR}/build/libsrc/src/libdynamic_library.so ${PROJECT_SOURCE_DIR}/libs/dynamic_library.so
	COMMAND cp ${PROJECT_SOURCE_DIR}/build/libsrc/src/libstatic_library.a ${PROJECT_SOURCE_DIR}/libs/static_library.a
	DEPENDS ${PROJECT_SOURCE_DIR}/build/libsrc/src/libdynamic_library.so
	DEPENDS ${PROJECT_SOURCE_DIR}/build/libsrc/src/libstatic_library.a
)
add_custom_target(install
	DEPENDS ${PROJECT_SOURCE_DIR}/libs/dynamic_library.so
	DEPENDS ${PROJECT_SOURCE_DIR}/libs/static_library.a	
)