#ifndef LIU_ALGO_U_TURN_PLANNER_H_
#define LIU_ALGO_U_TURN_PLANNER_H_
#include <vector>
#include "general_concepts.h"
#include "hybrid_a_star.h"

namespace liu_algo
{

class UTurnPlanner {
public:
  UTurnPlanner(const MotionConfig &motion_config);

  void SetEnvironment(const Lane &start, const Lane &end);

  void SetHybridAStarConfig(const hybrid_a_star::SearchConfig &search_config);

  std::vector<Point> Plan(std::vector<liu_algo::Point> *a_star_output, bool *goal_reached);

private:
  hybrid_a_star::GridInfo a_star_grid_;
  hybrid_a_star::HybridAStarSolver a_star_solver_;
  Lane start_lane_;
  Lane end_lane_;
  MotionConfig motion_config_;
  Point start_point_;
  Point end_point_;
};

} // namespace liu_algo

#endif //LIU_ALGO_U_TURN_PLANNER_H_