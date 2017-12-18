cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project("BlockChain4Fun")

set(CMAKE_LIBRARY_ARCHITECTURE "x86")
###########################################################
#For grouping project
set_property(GLOBAL PROPERTY USE_FOLDERS ON) 

#directory setting

set (LIB_DIR "${PROJECT_SOURCE_DIR}/lib")
set (CORE_DIR "${PROJECT_SOURCE_DIR}/core")
set (CORE_LIB "libblc_core")

#Find required package
#find_package()

#add sub directory to build tree
add_subdirectory(main)
add_subdirectory(core)

#deploy additional stuffs
#install(
#	DIRECTORY
#	DESTINATION
#	)