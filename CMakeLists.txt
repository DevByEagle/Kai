cmake_minimum_required(VERSION 3.10)
project(lily)

# Makes a hidden visibility preset on a static lib respected
# This is used to hide glfw's symbols from the library exports when building an so/dylib
# See https://cmake.org/cmake/help/latest/policy/CMP0063.html
cmake_policy(SET CMP0063 NEW)

# Include directory for modular CMake scripts
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Sets compiler flags and language standard
include(CompilerFlags)

# Load build options from a configuration file
include(CMakeOptions.txt)

# Add source files for synth in the src directory
add_subdirectory(src lily)

if (${BUILD_EXAMPLES})
  MESSAGE(STATUS "Building examples is enabled")
  add_subdirectory(examples)
endif()

# Enable testing for the project
enable_testing()