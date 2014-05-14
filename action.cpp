#include "action.h"

Action::Action(){
}


Action::Action (std::string op_name) {
  this->name = op_name;
  this->cost = 1;
}


std::string Action::toString() {
  std::stringstream retVal;
  retVal << "Pre:";
  for ( boost::container::vector< std::pair<int,int> >::iterator vecIter = pre_list.begin(); vecIter != pre_list.end() ; vecIter++ ) {
    retVal << vecIter->first << "=" << vecIter->second << ",";
  }
  retVal << " ; Eff:";
  for ( boost::container::vector< std::pair<int,int> >::iterator vecIter = eff_list.begin(); vecIter != eff_list.end() ; vecIter++ ) {
    retVal << vecIter->first << "=" << vecIter->second << ",";
  }
  retVal << ">\n";
  // for (auto i : range_names) {
  //   cout << i << ",";
  // }
  return retVal.str();
}


std::string Action::prettyToString(boost::container::vector<StateVar> &state_vars) {
  std::stringstream retVal;
  retVal << "Pre:";
  for ( boost::container::vector< std::pair<int,int> >::iterator vecIter = pre_list.begin(); vecIter != pre_list.end() ; vecIter++ ) {
    retVal << state_vars[vecIter->first].name << "=" << state_vars[vecIter->first].range_names[vecIter->second] << ",";
  }
  retVal << " ; Eff:";
  for ( boost::container::vector< std::pair<int,int> >::iterator vecIter = eff_list.begin(); vecIter != eff_list.end() ; vecIter++ ) {
    retVal << state_vars[vecIter->first].name << "=" << state_vars[vecIter->first].range_names[vecIter->second] << ",";
  }
  retVal << ">\n";
  // for (auto i : range_names) {
  //   cout << i << ",";
  // }
  return retVal.str();
}
