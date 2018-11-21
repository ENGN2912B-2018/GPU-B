cmake_minimum_required(VERSION 2.8)
project(gpub)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -p -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

add_subdirectory(src)
add_subdirectory(lib)

include_directories(inc)
add_executable(balltracker app.cpp)
target_link_libraries(balltracker ...)
