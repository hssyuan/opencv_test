cmake_minimum_required(VERSION 2.8)
set(OpenCV_DIR /home/hydroakri/opencv/build)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( DisplayImage threshold.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )

