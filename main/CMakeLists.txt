cmake_minimum_required( VERSION 3.0.0 FATAL_ERROR )

file(
	GLOB 
		MAIN_SRC
			src/*.cpp
	)

#Must be called prior to add_executable	
link_directories(
	${CURL_DIR}/lib
	${SSL_DIR}/lib
	#${CPPREST_DIR}/lib
	)
	
#executable binary	
add_executable( app ${MAIN_SRC} )

#naming debug target based on OS
if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
	set_target_properties (
		app
		PROPERTIES
			DEBUG_POSTFIX "64D"
			RELEASE_POSTFIX "64"
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

include_directories(
	app
		PRIVATE
			${CORE_DIR}/include
	)
	
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

#change debugging working dir to install directory where .DLLs are installed CMAKE 3.8 or higher 
set_target_properties(
	app 
		PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/build/install"
	)