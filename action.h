#ifndef ACTION_H
#define ACTION_H

#include <utility>
#include <string>
#include <boost/container/vector.hpp>
#include "state_var.h"

class Action {
 public:
  std::string name;
  int cost;
  boost::container::vector< std::pair<int,int> > pre_list;
  boost::container::vector< std::pair<int,int> > eff_list;

  Action ();
  Action (std::string op_name);
  std::string toString();
  std::string prettyToString(boost::container::vector<StateVar> &state_vars);
};

#endif
