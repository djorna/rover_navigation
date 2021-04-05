# Rover Navigation

**Disclaimer:** I started this project as part of [Western University's mars rover team](wemars.org), but have since abandoned it. The plan was to implement [A terrain description method for traversability analysis based on elevation grid map](https://github.com/djorna/rover_navigation/blob/master/papers/Terrain.pdf) in ROS using the [grid_map](http://wiki.ros.org/grid_map) library.

## Overview

This ROS package is an extension of ANYbotics' grid_map package to include point-cloud registration. 

TODO:
* Path planning with OMPL

## Requirements
* Ubuntu 16.04 with ROS kinetic
* ROS packages:  
  * [navigation stack](http://wiki.ros.org/navigation)
  * [grid_map](https://github.com/ANYbotics/grid_map)


## Installation

### Building from Source
#### Dependencies
```shell
sudo apt-get install libeigen3-dev
sudo apt-get install ros-kinetic-navigation
```
#### grid_map installation
(Copied from ANYbotics Instructions)

To build from source, clone the latest version from this repository into your catkin workspace and compile the package using

    cd catkin_ws/src
    git clone https://github.com/anybotics/grid_map.git
    cd ../
    catkin_make

To maximize performance, make sure to build in *Release* mode. You can specify the build type by setting

    catkin_make -DCMAKE_BUILD_TYPE=Release

```shell
cd ~/catkin_ws/src
git clone https://github.com/djorna/PathPlanning.git
source ../devel/
```

## Demo 

    # Download example pcl data
    cd ~/catkin_ws/src/path_planning
    ./data/load_data.bash

    # Show grid_map in rviz
    source ~/catkin_ws/devel/setup.bash
    roslaunch rover_navigation pcl_to_grid_map.launch
