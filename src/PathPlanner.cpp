/*! PathPlanner.cpp
 *
 * 
 * 
 */

// Heavy inspiration from https://github.com/davetcoleman/ompl_visual_tools.git

#include "rover_navigation/PathPlanner.hpp"

/*
namespace ob = ompl::base;
namespace og = ompl::geometric;
*/

PathPlanner::PathPlanner() {
  auto space(std::make_shared<ob::SE2StateSpace>());

  // Construct the state space we are planning in
  space_.reset( new ob::RealVectorStateSpace( DIMENSIONS ));

  // Define an experience setup class
  simple_setup_ = og::SimpleSetupPtr( new og::SimpleSetup(space_) );
  si_ = simpleSetup_->getSpaceInformation();

  // Set the planner
  //simple_setup_->setPlanner(ob::PlannerPtr(new og::RRTstar( si_ )));
  simpleSetup_->setPlanner(ob::PlannerPtr(new og::TRRT( si_ )));

  // Load the cost map
  cost_map_.reset(new ompl::base::CostMap2DOptimizationObjective( si_ ));
  
  // TODO: user grid_map instead

  // Load an alternitive optimization objective
  path_length_objective_.reset(new ompl::base::PathLengthOptimizationObjective( si_ ));
}

bool isStateValid(const ob::State *state) {
  return false;
}

void PathPlanner::planWithSimpleSetup()
{
  // construct the state space we are planning in
  auto space(std::make_shared<ob::SE3StateSpace>());
  ob::setVectorBounds bounds(3);
  bounds.setLow(-1);
  bounds.setHigh(1);

  space->setBounds(bounds);
}


void PathPlanner::setTRRTParams(double goalBias, double range) {
  trrtPlanner->setGoalBias(goalBias);
  trrtPlanner->setRange(range);
}

bool PathPlanner::plan(double seconds=2) {

  // Start and Goal State ---------------------------------------------
  ob::PlannerStatus solved;

  // Create the termination condition (duration, interval)
  ob::PlannerTerminationCondition ptc = ob::timedPlannerTerminationCondition( seconds, 0.1 );

  // set the start and goal states
  simpleSetup_->setStartAndGoalStates(start, goal);

  // attempt to solve the problem within x seconds of planning time
  solved = simpleSetup_->solve(ptc);

  if (solved)
  {
    if (!simple_setup_->haveExactSolutionPath())
    {
      ROS_WARN_STREAM_NAMED("plan","APPROXIMATE solution found");
      if (use_visuals_)
        visual_tools_->publishText(text_pose, "APPROXIMATE solution found");
    }
    else
    {
      ROS_DEBUG_STREAM_NAMED("plan","Exact solution found");
      if (use_visuals_)
        visual_tools_->publishText(text_pose, "Exact solution found");

    }

    if (use_visuals_)
    {
      if (runs == 1)
      {
        // display all the aspects of the solution
        publishPlannerData(false);
      }
      else
      {
        // only display the paths
        publishPlannerData(false);
      }
    }
  }
  else
  {
    ROS_ERROR("No Solution Found");
    if (use_visuals_)
      visual_tools_->publishText(text_pose, "No Solution Found");
  }

  return solved;

}

void randomState(ob::State *state, const ob::State *near, const double distance) {

  // Create sampler
  ob::StateSamplerPtr sampler = si_->allocStateSampler();

  while (true)
  {
    sampler->sampleUniformNear(state, near, distance); // samples (near + distance, near - distance)

    // Check if the sampled points are valid
    if( si_->isValid(state) )
    {
      return;
    }
    else
      ROS_INFO_STREAM_NAMED("temp","Searching for valid start/goal state");
  }

}
