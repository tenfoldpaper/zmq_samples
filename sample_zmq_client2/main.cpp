#include <zmq.hpp>
#include <zhelpers.hpp>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    
    bool gotMilk = true;
    cout << "Welcome to sample publisher & heartbeat REQ client" << endl;
    zmq::context_t context(1);
    zmq::socket_t pub(context, ZMQ_PUB);
    zmq::socket_t heart(context, ZMQ_REQ);
    pub.connect("tcp://127.0.0.1:7772");
    heart.connect("tcp://127.0.0.1:7782"); //heartb in the server 
    
    cout << "Starting loop" << endl;

    while(1){
        cout << "." << endl;
        zmq::message_t temp;
        if(gotMilk){
            s_send(heart, "");
            gotMilk = false;
            cout << ";";
        }
        heart.recv(&temp);
        gotMilk = true;
        //add a better check for heart.recv; 
        sleep(1);

        s_send(pub, "huehueheheuheu");
        s_send(pub, "whut");
        s_send(pub,"heh");
        cout << "Msg sent";
        cout << ":";
        cout << endl;
        sleep(1);

    }

    return 0;
}
