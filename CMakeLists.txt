cmake_minimum_required(VERSION 3.5)

# This is a header only library - nothing to build
# We're only using CMake to test

project(variolite)

#######################
# Project Setup
#######################

# C++14 support
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Testing
enable_testing()
include(TestHelper.cmake)

#######################
# Project Sources
#######################

include_directories(include)
add_subdirectory(tests)
