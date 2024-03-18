cmake_minimum_required(VERSION 3.27)
project(task2)

set(CMAKE_CXX_STANDARD 17)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(task2 ImageFilters.cpp
        ImageFilters.h)

target_link_libraries(task2 ${OpenCV_LIBS})