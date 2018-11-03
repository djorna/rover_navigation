/**              _______     __________          
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

class RoverNav
{

public:
  grid_map::GridMap map;

  RoverNav();

  virtual ~RoverNav();

  /** 
   * Register single point to Grid map if it fits.
   */
  void addPointToGridMap(const pcl::PointXYZ &point);

  /** 
   * Register entire point cloud to grid.
   */
  void getGridMap(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud);

   

}; /*RoverNav*/

} /*namespace rover*/