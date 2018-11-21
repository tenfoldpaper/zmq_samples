# Makefile for the sample ZMQ server

#TOL = /opt/Waj_Backup/Simtg_fix/simtg/tools
#INC = -I $(TOL)/zeromq/4.0.3/include/
#LIB = -L $(TOL)/zeromq/4.0.3/lib/ -Wl,-rpath,$(TOL)/zeromq/4.0.3/lib/
FLG = -lzmq -lpthread

sample: streamPub.cpp
	g++ -Wall $(INC) $(LIB) streamPub.cpp -o estream $(FLG)
	g++ -Wall satSub.cpp -o esatsub $(FLG)
clean: client2
	rm stream
