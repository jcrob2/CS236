cmake_minimum_required(VERSION 3.16)
project(CS236)

set(CMAKE_CXX_STANDARD 14)

include_directories(lab_0/project-0-main)

add_executable(CS236
        lab_0/project-0-main/Book.cpp
        lab_0/project-0-main/Book.h
        lab_0/project-0-main/BookCreator.cpp
        lab_0/project-0-main/BookCreator.h
        lab_0/project-0-main/BookListCreator.cpp
        lab_0/project-0-main/BookListCreator.h
        lab_0/project-0-main/Info.cpp
        lab_0/project-0-main/Info.h
        lab_0/project-0-main/Library.cpp
        lab_0/project-0-main/Library.h
        lab_0/project-0-main/main.cpp)
