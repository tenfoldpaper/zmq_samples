#include <zmq.hpp>
#include <zhelpers.hpp>
#include <iostream>
using namespace std;

int main(){
    zmq::context_t context(1);
    zmq::socket_t streamPub(context, ZMQ_STREAM);
    streamPub.connect("tcp://127.0.0.1:7770");
    cout << "Starting loop" << endl;
    string something;
    string what = "hehehehehe";
    while(1){
        getline(cin, something);
        zmq::message_t payload(what.size());
        memcpy((void*)payload.data(), (what.c_str()), payload.size());
        streamPub.send(payload);
        cout << "Sent the message!" << endl; 

    }
    return 0;
}
