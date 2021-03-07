#
# PROGRAM:  assign1
# AUTHOR:   Cortland Ervins
# Z-ID:     Z1813736
# DATE DUE: 2/11/19
#

#  Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

# Rule to compile source code file to object code
assign1.o: assign1.cpp
	g++ $(CCFLAGS) -c assign1.cpp

# Pseudo-target to remove object code and executable files clean:
clean:
	-rm *.o assign1


