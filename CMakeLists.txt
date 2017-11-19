cmake_minimum_required (VERSION 3.0)
set (CMAKE_CXX_STANDARD 11)

project (Seqalgo)

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Catch2/single_include)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

add_library(Seqalgo INTERFACE)
target_include_directories(Seqalgo INTERFACE seqalgo)
# seqalgo

add_subdirectory(test)
