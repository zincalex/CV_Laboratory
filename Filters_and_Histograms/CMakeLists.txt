cmake_minimum_required(VERSION 3.20)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(Lab2
        src/ImageFilters.cpp
        include/ImageFilters.h
        main.cpp)

target_link_libraries(Lab2 ${OpenCV_LIBS})