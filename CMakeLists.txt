cmake_minimum_required(VERSION 3.8)
project(sql_builder)

set(CMAKE_CXX_STANDARD 11)

#gtest路径
set(GTEST_LIB_PATH /opt/cdk/gtest/v1.8.0)

include_directories(
        ${GTEST_LIB_PATH}/include
)
link_directories(
        ${GTEST_LIB_PATH}/lib
)

add_subdirectory(sql-builder)
add_subdirectory(test)
