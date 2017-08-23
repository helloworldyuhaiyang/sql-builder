cmake_minimum_required(VERSION 2.8)
project(sql_builder)

set(CMAKE_MACOSX_RPATH 0)
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(sql-builder)
add_subdirectory(test)
