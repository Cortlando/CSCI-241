#
# PROGRAM:    dateTest
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign8: assign8.o
	g++ $(CCFLAGS) -o assign8 assign8.o

# Rules to compile source code files to object code
assign8.o: assign8.cpp 
	g++ $(CCFLAGS) -c assign8.cpp



# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8
