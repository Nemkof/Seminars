cmake_minimum_required(VERSION 3.29)
project(Task1_ForwardList)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Task1_ForwardList
    main.cpp
        ForwardList.h)
