#
#
# PROGRAM:  assign10
# AUTHOR:   Cortland Ervins
# Z-ID:     Z1813736
# DATE DUE: 4/25/19
#

# Compiler Variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign10: assign10.o
	g++ $(CCFLAGS) -o assign10 assign10.o

# Rules to compile source code files to object code
assign10.o: assign10.cpp List.h
	g++ $(CCFLAGS) -c assign10.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign10
