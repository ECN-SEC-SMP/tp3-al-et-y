cmake_minimum_required(VERSION 3.28)

project(TP3)

set (CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES    main.cpp
                    Forme.hpp
                    PointT.hpp
                    Rectangle.hpp) #Add source files here

add_executable(${PROJECT_NAME} ${SOURCE_FILES})