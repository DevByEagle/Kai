cmake_minimum_required(VERSION 3.10)
project(kargo)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Include directory for modular CMake scripts
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Sets compiler flags and language standard
include(CompilerFlags)

# Load build options from a configuration file
include(CMakeOptions.txt)

# Add source files for kargo in the src directory
add_subdirectory(src kargo)

# Enable testing for the project
enable_testing()