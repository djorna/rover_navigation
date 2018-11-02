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

#include <rover_nav.h>
#include <grid_map.h>
#include <pcl>

namespace rover {

RoverNav::RoverNav() {
  gridMap = GridMap({"elevation"});
}

~RoverNav() {}

void addPointToGridMap(const pcl::PointXYZ &point) {
  grid_map::Position(point.x, point.y);
  if (gridMap.isInside(position)) gridMap.at(position) = point.z;      
}

void getGridMap(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud) {   
      const int length = gridMap.getLength();
      const int cellSize = gridMap.getResolution();
      grid_map::Position position;        

      for (pcl::PointCloud<pcl::PointXYZ>::iterator point = cloud->begin();
            point < cloud->end(); 
            ++point) {
        addPointToGridMap(*point);
      }
}

} /*namespace rover*/
