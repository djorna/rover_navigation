
#include <ros/ros.h>
#include "PathPlanner.h"

int main(int argc, char** arcv) {


  ros::init(argc, argv, "path_planner");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise< //publish series of states??


  PathPlanner pp;
  



  ros::Rate rate(10);
  while (nh.ok()) {

    pub.publish();

    rate.sleep();
  }


  return 0;
}