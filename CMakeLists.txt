cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# Project name
project(Ingestor CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(include)

# Collect all source files
set(SOURCES
    source/extractor.cpp
    source/loader.cpp
    source/logger.cpp
    source/transformer.cpp
    source/pipeline_manager.cpp
    source/main.cpp
)

# Define executable
add_executable(Ingestor ${SOURCES})