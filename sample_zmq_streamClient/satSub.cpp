#include <zmq.hpp>
#include <zhelpers.hpp>
#include <iostream>
using namespace std;

int main(){
    bool gotMilk = true;
    zmq::context_t context(1);
    
    zmq::socket_t heartbeat(context, ZMQ_REP);
    zmq::socket_t sattxsimu(context, ZMQ_SUB);
    
    heartbeat.connect("tcp://127.0.0.1:7781");
    sattxsimu.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    sattxsimu.connect("tcp://127.0.0.1:7771");

    cout << "Starting loop" << endl;
    string something;
    while(1){ 
        s_recv(heartbeat);
        s_send(heartbeat, "");
        cout << s_recv(sattxsimu);
        cout << "next" << endl;
//        getline(cin, something);

    }
    return 0;
}
