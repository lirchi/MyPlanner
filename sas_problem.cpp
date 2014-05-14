#include "sas_problem.h"

SasProblem::SasProblem(){
}

SasProblem::SasProblem (bool metric, int num_of_state_vars, boost::container::vector<StateVar> &state_vars,
                        boost::container::vector<int> &initial_state, boost::container::vector< std::pair<int,int> > &goal_state,
                        int num_of_operators, boost::container::vector<Action> &actions) {
  this->metric = metric;
  this->num_of_state_vars = num_of_state_vars;
  this->state_vars = state_vars;
  this->initial_state = initial_state;
  this->goal_state = goal_state;
  this->num_of_operators = num_of_operators;
  this->actions = actions;
}
   
std::string SasProblem::toString() {
  std::stringstream retVal;
  retVal << name << "\n";
  retVal << "Num of state variables: " << num_of_state_vars << "\n";
  for ( boost::container::vector<StateVar>::iterator vecIter = state_vars.begin(); vecIter != state_vars.end() ; vecIter ++ ) {
    retVal << "   " << vecIter->toString();
  }
  retVal << "Num of operators: " << num_of_operators << "\n";
  for ( boost::container::vector<Action>::iterator vecIter = actions.begin(); vecIter != actions.end() ; vecIter ++ ) {
    //    retVal << "   " << vecIter->toString();
    retVal << "   " << vecIter->prettyToString(state_vars);
  }
  retVal << "\n" << "Initial state: \n";
  for ( unsigned int i=0; i<initial_state.size(); i++ ) {
    retVal << state_vars[i].name << "=" << state_vars[i].range_names[ initial_state[i] ] << " , ";
  }
  retVal << "\n" << "Goal state: \n";
  for ( boost::container::vector< std::pair<int,int> >::iterator vecIter = goal_state.begin(); vecIter != goal_state.end() ; vecIter++ ) {
        retVal << state_vars[vecIter->first].name << "=" << (state_vars[vecIter->first]).range_names[vecIter->second] << ",";
  }

  return retVal.str();
}
