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
set (CURL_DIR "${LIB_DIR}/curl-7.57.0-win32")
set (SSL_DIR "${LIB_DIR}/openssl-1.1.0-win32")
#TODO: refine this configuration once get clarification 
#from vcpkg  https://github.com/Microsoft/vcpkg/issues/2484
find_path(
	CPPREST_IMMEDIATE_DIR
	NAMES cpprestsdk_x86-windows/include/cpprest/http_client.h
	PATHS $ENV{Path}
)
set (CPPREST_DIR "${CPPREST_IMMEDIATE_DIR}/cpprestsdk_x86-windows")


find_path(
	BOOST_SYSTEM_DIR
	NAMES boost-system_x86-windows/include/boost/system/
	PATHS $ENV{Path}
)

find_path(
	BOOST_DATE_TIME_DIR
	NAMES boost-date-time_x86-windows/include/boost/date_time/
	PATHS $ENV{Path}
)

message("cpprest: " ${CPPREST_DIR}) 
message("boost date time: " ${BOOST_DATE_TIME_DIR})
message("boost system: " ${BOOST_SYSTEM_DIR}) 


#TODO: find_library,find_package does not work for boost, need to check 
#set(BOOST_ROOT )
#set(BOOST_LIBRARYDIR )
#set(Boost_USE_STATIC_LIBS ON)
#set(Boost_USE_MULTITHREADED ON)

#find_package(Boost)
#if (WIN32)
#  # disable autolinking in boost
#  add_definitions( -DBOOST_ALL_NO_LIB )
#
#  # force all boost libraries to dynamic link (we already disabled
#  # autolinking, so I don't know why we need this, but we do!)
#  add_definitions( -DBOOST_ALL_DYN_LINK )
#endif()



#add sub directory to build tree
add_subdirectory(main)
add_subdirectory(core)

#deploy additional stuffs
if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
install(
	DIRECTORY
		${CURL_DIR}/bin/
		${SSL_DIR}/bin/
		${CPPREST_DIR}/bin/
	DESTINATION
		"./install"
	)
endif()