#ifndef SEARCH_STATE_H
#define SEARCH_STATE_H

#include <string>
#include <boost/container/vector.hpp>
#include <sstream>
#include "sas_problem.h"

class SearchState {
 public:
  int num_of_vars;
  int* vars_vals;
  int g;
  int h;
  SearchState* parent_state;
  Action* creating_action;
  static SasProblem* sas_problem_desc;
  
  SearchState();
  SearchState(int* vars_vals, int g, int h, SearchState* parent_state, Action* creating_action);
  ~SearchState();

  std::string toString();
  int calcEstimate();
  boost::container::vector<SearchState> findSuccessors();
  bool operator==(const SearchState &other) const; // equality up to g value (in case we re-encounter the same state)
  bool isGoal();
  void assignInitState();
};

#endif
