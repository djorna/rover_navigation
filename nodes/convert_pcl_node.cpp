// rover_navigation
#include "rover_navigation/GridMap.hpp"

// ROS
#include <ros/ros.h>

// grid_map
#include <grid_map_ros/grid_map_ros.hpp>
#include <grid_map_core/iterators/GridMapIterator.hpp>

// pcl
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_ros/point_cloud.h>

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

  
  // Initialize node and publisher
  ros::init(argc, argv, "grid_map_simple_demo_x");
  ros::NodeHandle nh("~"); // namespace = home
  ros::Publisher publisher = nh.advertise<grid_map_msgs::GridMap>("grid_map", 1, true);

  // Point cloud publisher
  ros::Publisher pclPublisher = nh.advertise<pcl::PointCloud<pcl::PointXYZ>> ("points2", 1);
  
  // set cloud frame id 
  cloud->header.frame_id = "map";

  // Get grid map from point cloud  
  rover::GridMap map;
  map.setGeometry(Length(10, 10), 0.02);
  map.setFrameId("map");
  std::cout << "Initializing...\n";

  // initialize with zeros 
  // for (grid_map::GridMapIterator it(map); !it.isPastEnd(); ++it) {
  //   map.at("elevation", *it) = 0;
  // }

  map.addPointCloud(cloud);
 
  ROS_INFO("Created map with size %f x %f m (%i x %i cells).\n The center of the map is located at (%f, %f) in the %s frame.",
    map.getLength().x(), map.getLength().y(),
    map.getSize()(0), map.getSize()(1),
    map.getPosition().x(), map.getPosition().y(), map.getFrameId().c_str());

  ros::Rate rate(1); // rate in H
  while(nh.ok()) {
    ros::Time time = ros::Time::now();

    // Publish grid map
    map.setTimestamp(time.toNSec());
    grid_map_msgs::GridMap message;
    GridMapRosConverter::toMessage(map, message);
    publisher.publish(message);
    ROS_INFO_THROTTLE(1.0, "Grid map (timestamp %f) published.", message.info.header.stamp.toSec());

    pclPublisher.publish(cloud);

    rate.sleep();
  }
  

  return 0;
}