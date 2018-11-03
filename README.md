# PathPlanning

## Overview

This ROS package is an extension of ANYbotics' grid_map package to include real-time point-cloud registration, optimum path planning, and GPU optimization.

Featues:

## Requirements
* Ubuntu 16.04 with ROS kinetic
* ROS packages:  
  * [nagigation stack](http://wiki.ros.org/navigation)
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


## Installing Example Data
```shell
cd ~/catkin_ws/src/path_planning
./data/load_data.bash
```
