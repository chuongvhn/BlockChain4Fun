cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project("BlockChain4Fun")

set(CMAKE_LIBRARY_ARCHITECTURE "x86")
###########################################################
#For grouping project
set_property(GLOBAL PROPERTY USE_FOLDERS ON) 

#directory setting
set (CORE_DIR "${PROJECT_SOURCE_DIR}/core")
set (CORE_LIB "libblc_core")
set (LIB_DIR "${PROJECT_SOURCE_DIR}/lib")
set (CURL_LIB_DIR "${LIB_DIR}/curl-7.57.0-win32")
set (SSL_LIB_DIR "${LIB_DIR}/openssl-1.1.0-win32")

#Find required package
#find_package()

#add sub directory to build tree
add_subdirectory(main)
add_subdirectory(core)

#deploy additional stuffs
install(
	DIRECTORY
		${CURL_LIB_DIR}/bin/
		${SSL_LIB_DIR}/bin/
	DESTINATION
		"./install"
	)