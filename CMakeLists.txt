cmake_minimum_required(VERSION 3.10)

project(project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(project
    src/main.cpp
    src/EventGenerator.cpp
    src/Logger.cpp
    src/EventLogger.cpp
    src/Pipe.cpp
)