cmake_minimum_required(VERSION 3.7)
project(CacheLatency)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        LICENSE
        main.c
        README.md)

add_executable(CacheLatency ${SOURCE_FILES})
