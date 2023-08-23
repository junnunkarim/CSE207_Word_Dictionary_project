cmake_minimum_required(VERSION 3.27)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(dictionary)

# Set default build type to Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Define the source directory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# Add the include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Create an executable target
add_executable(dictionary
  ${SOURCE_DIR}/main.cpp
  ${SOURCE_DIR}/utility.cpp
  ${SOURCE_DIR}/word.cpp

  #${TESTS_DIR}/test_word.cpp
  #${SOURCE_DIR}/word.cpp

  #${TESTS_DIR}/test_bst.cpp

  #${TESTS_DIR}/test_list.cpp
)
