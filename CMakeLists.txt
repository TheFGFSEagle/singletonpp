cmake_minimum_required(VERSION 3.1.0)
project(singleton++ VERSION 1.0.0  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(singleton++ INTERFACE)
target_include_directories(singleton++ INTERFACE .)

install(
	FILES ${CMAKE_SOURCE_DIR}/singleton.hxx
	DESTINATION include
)

