cmake_minimum_required(VERSION 3.20)
project(task6)

set(CMAKE_CXX_STANDARD 17)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(task6
        main.cpp)

target_link_libraries(task6 ${OpenCV_LIBS})