# Makefile for the sample ZMQ server

TOL = /opt/Waj_Backup/Simtg_fix/simtg/tools
INC = -I $(TOL)/zeromq/4.0.3/include/
LIB = -L $(TOL)/zeromq/4.0.3/lib/ -Wl,-rpath,$(TOL)/zeromq/4.0.3/lib/
FLG = -lzmq -lpthread

sample: main.cpp
	g++ -Wall $(INC) $(LIB) main.cpp -o client $(FLG)

clean: client
	rm client
