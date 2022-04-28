cmake_minimum_required(VERSION 3.21)
project(Text_editor_)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS
        CS112-203-2nd-S1-20210049-20210067-20210133-A4-TextEditorFunc.h
        )
set(PROJECT_SOURCES
        CS112-203-2nd-S1-20210049-20210067-20210133-A4-TextEditorFunc.cpp
        CS112-203-2nd-S1-20210049-20210067-20210133-A4-TextEditorApp.cpp
        )

add_executable(Text_editor_ ${PROJECT_SOURCES} ${PROJECT_HEADERS})
