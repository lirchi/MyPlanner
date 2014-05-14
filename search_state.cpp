#include "search_state.h"

SasProblem* SearchState::sas_problem_desc;

SearchState::SearchState() {
}

SearchState::SearchState(int* vars_vals, int g, int h, SearchState* parent_state, Action* creating_action) {
  this->vars_vals = vars_vals;
  this->g = g;
  this->h = h;
  //  SearchSpace::sas_problem_desc = sas_problem_desc; -- it is static...
  this->parent_state = parent_state;
  this->creating_action = creating_action;
  this->num_of_vars = sas_problem_desc->num_of_state_vars;
}
 
SearchState::~SearchState() {
  delete[] vars_vals;
}

std::string SearchState::toString() {
  std::stringstream retVal;
  retVal << "\n" << "Current State: [";
  for ( unsigned int i=0; i<SearchState::sas_problem_desc->initial_state.size(); i++ ) {
    retVal << sas_problem_desc->state_vars[i].name << "=" << sas_problem_desc->state_vars[i].range_names[ vars_vals[i] ] << " , ";
  }
  retVal << "]\n";
  return retVal.str();
}

int SearchState::calcEstimate() {
  return g+h;
}

boost::container::vector<SearchState> SearchState::findSuccessors() {

  // copy current state
  int* new_vars_vals = new int[num_of_vars];
  memcpy (new_vars_vals, this->vars_vals, sizeof(int)*num_of_vars);
  // make changes by the operators
  // create new state object and add it to retVal vector
  
}

bool SearchState::operator==(const SearchState &other) const {
}

bool SearchState::isGoal() {
  
}

void SearchState::assignInitState() {
  vars_vals = new int[num_of_vars];
  std::copy ( sas_problem_desc->initial_state.begin(), sas_problem_desc->initial_state.end(), vars_vals );
}
