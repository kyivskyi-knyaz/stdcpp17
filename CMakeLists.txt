cmake_minimum_required(VERSION 3.30)
project(stdcpp17)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(stdcpp17
    fake.cpp
    IO.hpp
    iterator.hpp
    list.hpp
    main.cpp
    string.hpp
    vector.hpp)
