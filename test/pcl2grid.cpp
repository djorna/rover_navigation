
#include <RoverNav.hpp>
#include <ros/ros.h>
#include <grid_map_ros/grid_map_ros.hpp>
#include <grid_map_msgs/GridMap.h>


int main(int argv, char*[] argc) {

  // Get point cloud
  std::string pcdFile = argv[1];
  cout << "pcdFile:" << pcdFile << "\n";

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

	if (pcl::io::loadPCDFile<pcl::PointXYZ> (pcdFile, *cloud) == -1) //* load the file
	{
	  PCL_ERROR ("Couldn't read file %s\n", pcdFile);
	  return -1;
	}
	std::cout << "Loaded "
			<< cloud->width * cloud->height
			<< " data points from " << pcdFile
			<< std::endl;

  // Get grid map from point cloud
  nav RoverNav = RoverNav();
  nav.getGridMap(cloud);    

  return 0;
}