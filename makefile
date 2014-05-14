CC = g++ # the compiler 
CFLAGS = -Wall -I /usr/include/boost/ -std=c++11 # the compiler flags 

all: driver.o problem_reader.o action.o state_var.o sas_problem.o search_state.o
	$(CC) $(CFLAGS) driver.o problem_reader.o action.o state_var.o sas_problem.o search_state.o -o driver

driver:
	$(CC) $(CFLAGS) -c driver.cpp

debug: example1.o
	$(CC) -g $(CFLAGS) example1.cpp -o example1 
	ddd example1

memcheck:
	valgrind --leak-check=yes --xml=yes --xml-file=driver.log ./driver data.txt
	valkyrie --view-log=driver.log

gprof:
	gprof example1 gmonx.out

callgrind:
	valgrind --tool=callgrind ./driver data.txt

problem_reader: problem_reader.o
	$(CC) $(CFLAGS) -c problem_reader.cpp

action: action.o
	$(CC) $(CFLAGS) -c action.cpp

state_var: state_var.o
	$(CC) $(CFLAGS) -c state_var.cpp

sas_problem: sas_problem.o
	$(CC) $(CFLAGS) -c sas_problem.cpp

search_state: search_state.o
	$(CC) $(CFLAGS) -c search_state.cpp



clean:
	rm -rf *o *~ driver
