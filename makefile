# build an executable named circularqueue
all: CircularQueue.cpp
	g++ -g -Wall -o circularqueue CircularQueue.cpp

clean: 
	 $(RM) myprog
