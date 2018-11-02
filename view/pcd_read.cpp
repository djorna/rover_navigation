#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

int main (int argc, char** argv)
{
  // TODO: Add error handling for file
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
			<< " data points from test_pcd.pcd with the following fields: "
			<< std::endl;

  /*
	pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");
	viewer.showCloud(cloud);
	while (!viewer.wasStopped()){}
	*/
  cout << "Attempting...\n";
  
  for (pcl::PointCloud<pcl::PointXYZ>::iterator it = cloud->begin(); it < cloud->end(); ++it) {
    cout << (*it).x;
  }
  
  
  // Optionally print all points in point cloud
  /*
	for (size_t i = 0; i < cloud->points.size (); ++i)
	std::cout << "    " << cloud->points[i].x
				<< " "    << cloud->points[i].y
				<< " "    << cloud->points[i].z << std::endl;
	*/ 

	return (0);
}