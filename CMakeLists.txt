cmake_minimum_required(VERSION 3.27)

project(dictionary)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the source directory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add the include directories
include_directories(${SOURCE_DIR}/include)

# Create an executable target
add_executable(MyExecutable
  ${SOURCE_DIR}/main.cpp
  ${SOURCE_DIR}/include/binary_search_tree.cpp
  ${SOURCE_DIR}/include/dictionary.cpp
)
