cmake_minimum_required(VERSION 3.20)
project(imageMatching)

set(CMAKE_CXX_STANDARD 17)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(imageMatching
        main.cpp
        include/FeatureMatchers.h
        src/FeatureMatchers.cpp
)

target_link_libraries(imageMatching ${OpenCV_LIBS})