cmake_minimum_required(VERSION 3.17)
project(Sort)
MATH(EXPR stack_size "100*1024*1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
set(CMAKE_CXX_STANDARD 14)

add_executable(Sort main.cpp quick_sort.h select_kth_smallest.h merge_sort.h)