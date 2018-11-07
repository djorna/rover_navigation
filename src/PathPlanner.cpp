/*! PathPlanner.cpp
 *
 * 
 * 
 */

#include "rover_navigation/PathPlanner.hpp"

PathPlanner::PathPlanner() {}

bool isStateValid(const ob::State *state) {
  return false;
}

void planWithSimpleSetup()
{
  // construct the state space we are planning in
  auto space(std::make_shared<ob::SE3StateSpace>());
  ob::setVectorBounds bounds(3);
  bounds.setLow(-1);
  bounds.setHigh(1);

  space->setBounds(bounds);
}