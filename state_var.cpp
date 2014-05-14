#include "state_var.h"

StateVar::StateVar(){
}

StateVar::StateVar (std::string var_name, int var_range) {
  name = var_name;
  range = var_range;
  range_names.reserve(range);
}

std::string StateVar::toString() {
  std::stringstream retVal;
  retVal << "Variable name: " << name << " ; Range-size: " << range << " ; [";
  for ( boost::container::vector<std::string>::iterator vecIter = range_names.begin(); vecIter != range_names.end() ; vecIter++ ) {
    retVal << *vecIter << ",";
  }
  retVal << "] \n";
  // for (auto i : range_names) {
  //   cout << i << ",";
  // }
  return retVal.str();
}
