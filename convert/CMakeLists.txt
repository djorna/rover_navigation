cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

set (CMAKE_CXX_STANDARD 11)

project(pcl_visualizer_viewports)

find_package(PCL 1.2 REQUIRED)
find_package(Boost REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (xyz2pcd xyz2pcd.cpp)
target_link_libraries (xyz2pcd ${PCL_LIBRARIES})
