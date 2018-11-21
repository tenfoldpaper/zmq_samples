#include <zmq.hpp>
#include <zhelpers.hpp>
#include <iostream>
#include <string>
using namespace std;

int main(){
    bool gotMilk = true;
    zmq::context_t context(1);
    
    zmq::socket_t heartbeat(context, ZMQ_REQ);
    zmq::socket_t sattxsimu(context, ZMQ_PUB);
    
    heartbeat.connect("tcp://127.0.0.1:7782");
    sattxsimu.connect("tcp://127.0.0.1:7772");

    cout << "Starting loop" << endl;
    string something;
    while(1){ 
        cin >> something;
        zmq::message_t payload(something.size());
        cout << "what" << endl;
        memcpy((void*)payload.data(), (something.c_str()), payload.size());
        cout << "what2" << endl;
        s_send(heartbeat, "");
        string hello = s_recv(heartbeat);
        cout << "what" << endl;
        cout << payload.data() << endl;
        cout << something << endl;
        //sattxsimu.send(payload); 
        s_send(sattxsimu, something);
        cout << "next" << endl;
//        getline(cin, something);

    }
    return 0;
}
