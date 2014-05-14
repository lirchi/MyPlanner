#ifndef PROBLEM_READER_H
#define PROBLEM_READER_H

// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include<boost/tokenizer.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "state_var.h"
#include "action.h"
#include "sas_problem.h"
#include<boost/container/vector.hpp>

class ProblemReader {
 public:

  std::string line;
  bool metric;
  int num_of_state_vars;
  boost::container::vector<StateVar> state_vars;
  boost::container::vector<int> initial_state;
  boost::container::vector< std::pair<int,int> > goal_state;
  int num_of_actions;
  boost::container::vector<Action> actions;
  SasProblem* original_sas_problem;

  ProblemReader (std::string fname);

  SasProblem* getSasProblem();

};

#endif
