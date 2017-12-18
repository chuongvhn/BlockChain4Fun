cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
##################################################
file(
	GLOB 
		MAIN_SRC
			src/*.cpp
	)
	
#executable binary
add_executable( app ${MAIN_SRC} )

#naming debug target based on OS
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set_target_properties (
		app
			PROPERTIES
				DEBUG_POSTFIX "64D"
				RELEASE_POSTFIX"64"
				RELWITHDEBINFO_POSTFIX "64RD"
	)
else()
	set_target_properties (
		app
			PROPERTIES
				DEBUG_POSTFIX "D"
				RELWITHDEBINFO_POSTFIX "RD"
	)
endif()

target_include_directories(
	app
		PRIVATE
			${CORE_DIR}/include
	)
	
#TODO: verify dependency specifying 
target_link_libraries(
	app
		${CORE_LIB}
	)
	
install(
	TARGETS
		app
	RUNTIME
		DESTINATION "./install"
	)