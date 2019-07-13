cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project("BlockChain4Fun")

set(CMAKE_LIBRARY_ARCHITECTURE "x86")

#For grouping project
set_property(GLOBAL PROPERTY USE_FOLDERS ON) 

#path setting
set(CORE_DIR "${PROJECT_SOURCE_DIR}/core")
set(CORE_LIB "libblc_core")
set(LIB_DIR "${PROJECT_SOURCE_DIR}/lib")
set(CURL_DIR "${LIB_DIR}/curl-7.57.0-win32")
set(SSL_DIR "${LIB_DIR}/openssl-1.1.0-win32")



#add sub directory to build tree
add_subdirectory(main)
add_subdirectory(core)

#deploy additional stuffs
if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
install(
	DIRECTORY
		${LIB_DIR}/bin/
		${CURL_DIR}/bin/
		#${SSL_DIR}/bin/
		${CPPREST_DIR}/bin/
		${BOOST_SYSTEM_DIR}/bin/
		${BOOST_DATE_TIME_DIR}/bin/
		
	DESTINATION
		"./install"
	)
endif()
