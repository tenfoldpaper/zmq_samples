#include <zmq.hpp>
#include <zhelpers.hpp>
#include <iostream>

using namespace std;

int main(int argc, char* argv){
    
    bool gotMilk = true;
    cout << "Welcome to sample publisher & heartbeat REQ client" << endl;
    zmq::context_t context(1);
    zmq::socket_t pub(context, ZMQ_PUB);
    zmq::socket_t heart(context, ZMQ_REQ);
    pub.connect("tcp://127.0.0.1:5562");
    heart.connect("tcp://127.0.0.1:5563"); //heartb in the server 
    
    cout << "Starting loop" << endl;

    while(1){
        cout << ".";
        zmq::message_t temp;
        if(gotMilk){
            s_send(heart, "");
            gotMilk = false;
            cout << ";";
        }
        heart.recv(&temp);
        gotMilk = true;
        //add a better check for heart.recv; 

        s_send(pub, "huehueheheuheu");
        cout << "Msg sent";
        cout << ":";
        cout << endl;
        sleep(1);

    }

    return 0;
}
