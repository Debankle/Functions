cmake_minimum_required(VERSION 2.8)

project(Functions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

if(UNIX)
    set(CMAKE_CXX_FLAGS "-Wall -O2 --pedantic-errors -DGCC=\"$(shell which gcc)\"")
endif()

include_directories("${Functions_SOURCE_DIR}/include")
file(GLOB Functions_SOURCES "${Functions_SOURCE_DIR}/src/*.cpp")

add_executable(func ${Functions_SOURCES})