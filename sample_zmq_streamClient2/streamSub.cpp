#include <zmq.hpp>
#include <zhelpers.hpp>
#include <iostream>
using namespace std;

int main(){
    zmq::context_t context(1);
    zmq::socket_t streamSub(context, ZMQ_STREAM);
    streamSub.connect("tcp://127.0.0.1:7770");
    cout << "Starting loop" << endl;
    while(1){
        zmq::message_t recvMsg; 
        streamSub.recv(&recvMsg);
        string recvStr = string(static_cast<char*>(recvMsg.data()), recvMsg.size());
        cout << recvStr << endl;

    }
    return 0;
}
