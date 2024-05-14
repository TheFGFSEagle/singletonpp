cmake_minimum_required(VERSION 3.1.0)
project(singleton++ VERSION 1.0.0  LANGUAGES CXX)

include(CTest)
set(CMAKE_CXX_STANDARD 20)

option(ENABLE_TESTING "Whether to build testing executables" ON)

add_library(singleton++ INTERFACE)
target_include_directories(singleton++ INTERFACE .)
if(ENABLE_TESTING)
	add_subdirectory(tests)
endif()


install(
	FILES ${CMAKE_SOURCE_DIR}/singleton.hxx
	DESTINATION include
)

