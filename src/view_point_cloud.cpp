#include <pcl/tools/xyz2pcd.cpp>


int main() {
  string point_cloud_dir = "../p2at_met";

  // Convert xyz file to pcd
  string file_pcd = xyz2pcd(point_cloud_dir);

  // Visualize point cloud

  return 0;
}
