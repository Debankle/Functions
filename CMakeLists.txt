# Make sure to specify CC and CXX before running cmake

cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME Functions)
project(${PROJECT_NAME})

option(test "Build and run tests" OFF)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/bin")
set(CMAKE_CXX_FLAGS "-Wall -O2 --pedantic-errors -DGCC=\"$(shell which gcc)\"")

include_directories("${Functions_SOURCE_DIR}/include")
file(GLOB Functions_SOURCES "${Functions_SOURCE_DIR}/src/*.cpp")

if(test)
    add_executable(test "tests/Test.cpp")
    add_test(NAME func_test COMMAND test)
    set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${Functions_SOURCE_DIR}/tests")
endif()

add_executable(func ${Functions_SOURCES})