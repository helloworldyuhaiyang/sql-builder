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
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
	install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
else (CMAKE_SYSTEM_NAME MATCHES "Windows")
	install(TARGETS ${PROJECT_NAME}
	LIBRARY DESTINATION lib 
	ARCHIVE DESTINATION lib)
endif()