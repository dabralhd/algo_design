cmake_minimum_required(VERSION 3.14)
project(algo_library)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

set(ALGO_SOURCES
#bin_search.cpp binary_search.h
#math_functions.cpp math_functions.h
rotated_sorted_array.cpp rotated_sorted_array.h
)

add_subdirectory(binary_tree)
add_subdirectory(bin_search)
add_subdirectory(math_functions)

add_library(algo_library OBJECT ${ALGO_SOURCES})

#set(HEADER_FILES rotated_sorted_array.h)

