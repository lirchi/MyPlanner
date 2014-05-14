#ifndef SAS_PROBLEM_H
#define SAS_PROBLEM_H

#include <sstream>
#include <utility>
#include <string>
#include <boost/container/vector.hpp>
#include "action.h"
#include "state_var.h"

class SasProblem {
 public:
  std::string name;
  bool metric;
  int num_of_state_vars;
  boost::container::vector<StateVar> state_vars;
  boost::container::vector<int> initial_state;
  boost::container::vector< std::pair<int,int> > goal_state;
  int num_of_operators;
  boost::container::vector<Action> actions;
  
  SasProblem ();
  SasProblem (bool metric, int num_of_state_vars, boost::container::vector<StateVar> &state_vars,
              boost::container::vector<int> &initial_state, boost::container::vector< std::pair<int,int> > &goal_state,
              int num_of_operators, boost::container::vector<Action> &actions);
  std::string toString();
};

#endif
