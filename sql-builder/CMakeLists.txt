cmake_minimum_required(VERSION 3.8)
project(sql_builder)

set(CMAKE_CXX_STANDARD 11)

set(HEAD_FILES
        SqlModel.h
        SelectModel.h
        Column.h
        InsertModel.h
        UpdateModel.h
        DeleteModel.h
        Util.h
        )

set(SOURCE_FILES
        SqlModel.cpp
        SelectModel.cpp
        Column.cpp
        InsertModel.cpp
        UpdateModel.cpp
        DeleteModel.cpp
        )

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME})

#设置头文件的安装路径
install(FILES ${HEAD_FILES} DESTINATION include/sql-builder)

#设置库文件的安装路径
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
#install(FILES TaijiRedis DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)