// path_planning
#include "path_planning/RoverNav.hpp"

// ROS
#include <ros/ros.h>

// grid_map
#include <grid_map_ros/grid_map_ros.hpp>

// pcl
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

using namespace grid_map;
using namespace rover;

int main(int argc, char** argv) {

  // Get point cloud
  std::string pcdFile = argv[1];
  std::cout << "pcdFile:" << pcdFile << "\n";

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

	if (pcl::io::loadPCDFile<pcl::PointXYZ> (pcdFile, *cloud) == -1) // load the file
	{
	  PCL_ERROR ("Couldn't read file %s\n", pcdFile);
	  return -1;
	}
	std::cout << "Loaded "
			<< cloud->width * cloud->height
			<< " data points from " << pcdFile
			<< std::endl;

  
  // Get grid map from point cloud
  
  rover::RoverNav nav;

  nav.map.setGeometry(Length(100, 100), 0.03, Position(0.0, 0.0));
  nav.getGridMap(cloud);
 
  ROS_INFO("Created map with size %f x %f m (%i x %i cells).\n The center of the map is located at (%f, %f) in the %s frame.",
    nav.map.getLength().x(), nav.map.getLength().y(),
    nav.map.getSize()(0), nav.map.getSize()(1),
    nav.map.getPosition().x(), nav.map.getPosition().y(), nav.map.getFrameId().c_str());

  
  /*
  for (GridMapIterator it(nav.map); !it.isPastEnd(); ++it) {
    std::cout << nav.map.at("elevation", *it) << "\n";
  }
  

  
  
  // Initialize node and publisher
  ros::init(argc, argv, "convert_pcl_node");
  ros::NodeHandle nh("~"); // namespace = home
  ros::Publisher publisher = nh.advertise<grid_map_msgs::GridMap>("grid_map", 1, true);

  // 
  ros::Rate rate(30.0);
  while(nh.ok()) {
    ros::Time time = ros::Time::now();

    // Publish grid map
    nav.map.setTimestamp(time.toNSec());
    grid_map_msgs::GridMap message;
    GridMapRosConverter::toMessage(nav.map, message);
    publisher.publish(message);
    ROS_INFO_THROTTLE(1.0, "Grid map (timestamp %f) published.", message.info.header.stamp.toSec());

    rate.sleep();
  }
  */

  return 0;
}