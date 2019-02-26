/*! PathPlanner.hpp
 *
 * 
 * 
 * 
 */


// Open Motion Planing Library includes
#include <ompl/geometric/SimpleSetup.h>
#include <ompl/geometric/planners/rrt/TRRT.h>
#include <ompl/base/PlannerTerminationCondition.h>
#include <ompl/base/objectives/PathLengthOptimizationObjective.h>

namespace ob = ompl::base;
namespace og = ompl::geometric;

class PlathPlanner {

public:
  bool isStateValid(const ob::State *state);
  void simpleSetup();

  void setTRRTParams(double goalBias, double range, double motionCost);

  void setStart();

  void randomState(ob::State *state, const ob::State *near, const double distance);

  bool plan(const int& run_id, const int& runs);

private:
  og::SimpleSetupPtr simpleSetup_;

  og::TRRT trrtPlanner_;

  ob::StateSpacePtr space_;

  // Remember what space we are working in
  ompl::base::SpaceInformationPtr si_;

}