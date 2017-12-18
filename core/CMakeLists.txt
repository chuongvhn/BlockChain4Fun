cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
##################################################
file(
	GLOB 
		CORE_SRC
			src/*.cpp
	)
file(
	GLOB
		CORE_INCLUDE
			include/*.h
			include/*.hpp
	)
	
add_library(
	libblc_core
		STATIC
		${CORE_SRC}
		${CORE_INCLUDE}
	)

target_include_directories(
	libblc_core
		PRIVATE
			include
			#add dependencies 
			${}
	)
			

	
