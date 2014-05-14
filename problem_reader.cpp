// reading a text file
#include "problem_reader.h"

using namespace std;
using namespace boost;

ProblemReader::ProblemReader(std::string fname) {

  ifstream myfile (fname.c_str());

  if (myfile.is_open()) {

    // Read version section (3 lines)
    getline (myfile,line);
    getline (myfile,line);
    getline (myfile,line);

    // Read metric section (3 lines) and update metric flag
    getline (myfile,line);
    getline (myfile,line);
    if (line.compare("0") == 0)
      metric = false;
    else
      metric = true;
    getline (myfile,line);

    // Read variables section
    getline (myfile,line);  // number of state variables
    num_of_state_vars = atoi ( line.c_str() );
    state_vars.reserve(num_of_state_vars); //********************* is resize instead of reserve needed?
    for (int i=0; i<num_of_state_vars; i++) {
      getline (myfile,line); // begin_variable -- disregard
      getline (myfile,line); // variable name
      string var_name = line;
      getline (myfile,line); // axiom level -- disregard
      getline (myfile,line); // variable range
      int var_range = atoi(line.c_str());
      state_vars.emplace_back ( var_name, var_range );
      //      state_vars[i].range_names.reserve(var_range);  ********************** already done inside
      for (int j=0; j<var_range; j++) {
        getline (myfile,line);
        state_vars[i].range_names.push_back(line);
      }
      getline (myfile,line); // end_variable -- disregard
      //      cout << state_vars[i].toString() << "\n";
    }
    
    // Read mutex section (-- and disregard)
    for ( ; line.compare("begin_state") ; getline(myfile,line) ) {}

    // Read initial state section
    for (int i=0; i<num_of_state_vars; i++) {
      getline (myfile,line);
      int val = atoi(line.c_str());
      initial_state.push_back(val);
    }
    getline(myfile,line); // end_state -- disregard

    // Read goal state section
    getline(myfile,line); // begin_goal -- disregard
    getline (myfile,line);
    int goal_len = atoi(line.c_str());
    for (int i=0; i<goal_len; i++) {
      getline (myfile,line);
      tokenizer<> tok(line);
      tokenizer<>::iterator beg=tok.begin();
      int var = atoi ( (*beg).c_str() );
      beg++;
      int val = atoi ( (*beg).c_str() );
      pair<int,int> curr_pair;
      curr_pair.first = var;
      curr_pair.second = val;
      goal_state.push_back(curr_pair);
    }
    getline(myfile,line); // end_goal -- disregard

    // Read operators section
    getline (myfile,line); // number of operators
    num_of_actions = atoi(line.c_str());
    actions.reserve (num_of_actions);
    for (int i=0; i<num_of_actions; i++) {
      getline (myfile,line); // begin_operator -- disregard
      getline (myfile,line); // operator name
      actions.emplace_back ( line );
      getline (myfile,line); // number of prevail conditions
      int num_of_prevail = atoi ( line.c_str() );
      // read prevails
      for (int j=0; j<num_of_prevail; j++) {
	getline (myfile,line); // each line is var val pair
        tokenizer<> tok(line);
        tokenizer<>::iterator beg=tok.begin();
        int var = atoi ( (*beg).c_str() );
        beg++;
        int val = atoi ( (*beg).c_str() );
        pair<int,int> curr_pair;
        curr_pair.first = var;
        curr_pair.second = val;
	actions[i].pre_list.push_back ( curr_pair );
      }
    
      // read effects
      getline (myfile,line); // number of effect conditions
      int num_of_eff = atoi ( line.c_str() );
      for (int j=0; j<num_of_eff; j++) {
	getline (myfile,line); // each line is
        tokenizer<> tok(line);
        tokenizer<>::iterator beg=tok.begin();
	int num_of_eff_cond = atoi ( (*beg).c_str() );
	if (num_of_eff_cond != 0)
	  cout << "NOT SUPPORTED\n";
        beg++;
        int var = atoi ( (*beg).c_str() );
        beg++;
        int pre_val = atoi ( (*beg).c_str() );
        beg++;
        int eff_val = atoi ( (*beg).c_str() );
        pair<int,int> pre_pair,eff_pair;
        pre_pair.first = var;
        pre_pair.second = pre_val;
        eff_pair.first = var;
        eff_pair.second = eff_val;
	if (pre_val != -1)
	  actions[i].pre_list.push_back ( pre_pair );
	actions[i].eff_list.push_back ( eff_pair );
      }

      getline (myfile,line); // operator cost
      if (metric == true)    // in case of false, action already initiated to have cost=1
	actions[i].cost = atoi ( line.c_str() );

      getline (myfile,line); // end_operator -- disregard 
    } // done reading operators

    // read axioms -- disregard


    //    while ( getline (myfile,line) ) {
    //      tokenizer<> tok(line);
    //      for(tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg) {
    //	cout << *beg << "\n";
    //      }
      //      cout << line << '\n';
    //    }
    myfile.close();
  } // end reading file

  else cout << "Unable to open file"; 

  original_sas_problem = new SasProblem(metric, num_of_state_vars, state_vars, initial_state, goal_state, num_of_actions, actions);

}


SasProblem* ProblemReader::getSasProblem() { 
  return original_sas_problem; 
}

