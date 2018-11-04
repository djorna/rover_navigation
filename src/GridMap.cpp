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

#include "path_planning/GridMap.hpp"

namespace rover {

GridMap::GridMap() {
  grid_map::GridMap({"elevation"});
  //map = grid_map::GridMap({"elevation"});  
}

//GridMap::~GridMap() {}

void GridMap::addPoint(const pcl::PointXYZ& point) {
  grid_map::Position position(point.x, point.y);
  if (this->isInside(position)) {
    // Delete this later : for debugging
    //std::cout << "Added point at (" << point.x << ", " 
    //          << point.y << ") with value " << point.z << "\n";
    //
    this->atPosition("elevation", position) = point.z;  
    //std::cout << "confirm position: " << this->atPosition("elevation", position) << "\n";
  }
}

void GridMap::addPointCloud(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& cloud) {   
      //const int length = map.getLength();
      //const int cellSize = map.getResolution();
      //grid_map::Position position;        

      for (pcl::PointCloud<pcl::PointXYZ>::const_iterator it = cloud->begin();
            it < cloud->end(); 
            ++it) {
        addPoint(*it);
      }
}

} /*namespace rover*/
