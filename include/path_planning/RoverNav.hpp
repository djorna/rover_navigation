/**              _______     __________          
 *              /\   _   \  /\____   __\         
 *              \ \  \ \  \ \/__/ \  \ /          
 *               \ \  \_/  |    \__\  \
 *                \ \_____/    / \_____\ 
 *                 \/____/     \ /_____/
 */ 

#pragma once;

#include <pcl>

namespace rover {

class RoverNav
{

public:
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

private:
  grid_map::GridMap gridMap;

}; /*RoverNav*/

} /*namespace rover*/