/**
 * Implementation of http://journals.sagepub.com/doi/full/10.1177/1729881417751530
 * by Xiangrui Meng, Zhiqiang Cao, Shuang Liang, Lei Pang,
 * Shuo Wang, and Chao Zhou
 * 
 * Using grid_map library by ANYbotics
 */

/**              _______     __________          
 *              /\   _   \  /\____   __\         
 *              \ \  \ \  \ \/__/ \  \ /          
 *               \ \  \_/  |    \__\  \
 *                \ \_____/    / \_____\ 
 *                 \/____/     \ /_____/
 */ 

#include "path_planning/RoverNav.hpp"

namespace rover {

RoverNav::RoverNav() {
  map = grid_map::GridMap({"elevation"});
}

RoverNav::~RoverNav() {}

void RoverNav::addPointToGridMap(const pcl::PointXYZ &point) {
  grid_map::Position position(point.x, point.y);
  if (map.isInside(position)) {
    // Delete this later
    std::cout << "Added point at " << point.x << " " 
              << point.y << " with value " << point.z;
    map.atPosition("elevation", position) = point.z;  
  }
}

void RoverNav::getGridMap(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud) {   
      //const int length = map.getLength();
      //const int cellSize = map.getResolution();
      //grid_map::Position position;        

      for (pcl::PointCloud<pcl::PointXYZ>::const_iterator point = cloud->begin();
            point < cloud->end(); 
            ++point) {
        addPointToGridMap(*point);
      }
}

} /*namespace rover*/
