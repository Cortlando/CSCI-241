#
# PROGRAM: Lab Training Exercise
# AUTHOR: Cortland Ervins
#

CCFLAGS = -Wall -std=c++11

labtrain: labtrain.o
	g++ $(CCFLAGS) -o labtrain labtrain.o

labtrain.o: labtrain.cpp
	g++ $(CCFLAGS) -c labtrain.cpp

clean:
	- rm *.o labtrain
