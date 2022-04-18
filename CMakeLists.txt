cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(togetherbot-cpp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT EXISTS extern/DPP)
	message(FATAL_ERROR "The submodule 'DPP' is not installed. Clone this repo with submodules!")
endif()

add_subdirectory(extern/DPP)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(togetherbot ${SRC_FILES})

target_include_directories(togetherbot PUBLIC include)
target_link_libraries(togetherbot PRIVATE dpp)

