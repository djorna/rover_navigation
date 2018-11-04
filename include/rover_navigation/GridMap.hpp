/* GridMap.hpp
 *               _______     __________          
 *              /\   __  \  /\____   __\         
 *              \ \  \  \ \ \/__/ \  \ /          
 *               \ \  \_/  |    \__\  \
 *                \ \_____/    / \_____\ 
 *                 \/____/     \ /_____/
 */ 

#pragma once

// PCL
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

// grid_map
#include <grid_map_core/GridMap.hpp>

namespace rover {

class GridMap : public grid_map::GridMap
{

public:

  GridMap();

  /** 
   * Register single point to Grid map if it fits.
   */
  void addPoint(const pcl::PointXYZ &point);

  /** 
   * Register entire point cloud to grid.
   */
  void addPointCloud(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& cloud);   

}; /* GridMap */

} /* namespace rover */