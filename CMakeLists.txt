cmake_minimum_required(VERSION 3.8)
project(grid_enviroment)

set(CMAKE_CXX_STANDARD 11)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(SOURCE_FILES
        environment.cc environment.h
        defs.h
        agent.cc agent.h
        mainmap.cc)

add_executable(grid_enviroment ${SOURCE_FILES})
target_link_libraries(grid_enviroment ${CURSES_LIBRARIES})