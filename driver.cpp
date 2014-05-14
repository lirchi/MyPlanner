// reading a text file
#include <iostream>
#include "problem_reader.h"
#include "sas_problem.h"
#include "search_state.h"

using namespace std;

int main (int argc, char** argv) {

  // read SAS problem from FD translator into prob1
  ProblemReader pr = ProblemReader(argv[1]);
  SasProblem* prob1 = pr.getSasProblem();
  prob1->name = "Lir";
  cout << prob1->toString() << "\n";

  // generate initial state
  SearchState::sas_problem_desc = prob1;
  SearchState* s1 = new SearchState (NULL,0,0,NULL,NULL);
  s1->assignInitState();
  delete (prob1);
  delete (s1);

  return 0;

}
