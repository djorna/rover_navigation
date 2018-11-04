/**
 * Implementation of http://journals.sagepub.com/doi/full/10.1177/1729881417751530
 * by Xiangrui Meng, Zhiqiang Cao, Shuang Liang, Lei Pang,
 * Shuo Wang, and Chao Zhou
 * 
 * Using grid_map library by ANYbotics
 */

/* GridMap.cpp
 *               _______     __________          
 *              /\   _   \  /\____   __\         
 *              \ \  \ \  \ \/__/ \  \ /          
 *               \ \  \_/  |    \__\  \
 *                \ \_____/    / \_____\ 
 *                 \/____/     \ /_____/
 */ 

#include "rover_navigation/GridMap.hpp"

namespace rover {

GridMap::GridMap() : grid_map::GridMap({"elevation"}) {}

void GridMap::addPoint(const pcl::PointXYZ& point) {
  grid_map::Position position(point.x, point.y);
  if (this->isInside(position)) {
    this->atPosition("elevation", position) = point.z;  
  }
}

void GridMap::addPointCloud(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& cloud) {   
      for (pcl::PointCloud<pcl::PointXYZ>::const_iterator it = cloud->begin();
            it < cloud->end(); 
            ++it) {
        addPoint(*it);
      }
}

} /* namespace rover */
