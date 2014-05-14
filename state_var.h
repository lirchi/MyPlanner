#ifndef STATE_VAR_H
#define STATE_VAR_H

#include <string>
#include <boost/container/vector.hpp>
#include <sstream>

class StateVar {
 public:
  std::string name;
  int range;
  boost::container::vector<std::string> range_names;

  StateVar ();
  StateVar (std::string var_name, int var_range);
  std::string toString();
};

#endif
