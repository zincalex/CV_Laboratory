cmake_minimum_required(VERSION 3.20)
project(task5)

set(CMAKE_CXX_STANDARD 17)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(task5
        main.cpp)

target_link_libraries(task5 ${OpenCV_LIBS})