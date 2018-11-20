#include <zmq.hpp>
#include <zhelpers.hpp>
#include <iostream> 

using namespace std;
int main(int argc, char* argv[]){
;
    bool gotMilk = true;
    string smsg; 
    zmq::context_t context(1);
    zmq::socket_t sub(context, ZMQ_SUB);
    zmq::socket_t heart(context, ZMQ_REQ);

    sub.connect("tcp://127.0.0.1:5560");
    heart.connect("tcp://127.0.0.1:5561");

    sub.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    
    zmq::pollitem_t items[] = {
        { sub, 0, ZMQ_POLLIN, 0},
        { heart, 0, ZMQ_POLLIN, 0}
    };
    while(1){
    try{
        cout << '.';
        zmq::message_t msg;
        if(gotMilk){
            s_send(heart, "");
            gotMilk = false;
        }
        else{
            cout << "No reply received yet;" << endl;
        }
        zmq::poll(items, 2, -1);
        if(items[0].revents & ZMQ_POLLIN){
            smsg = s_recv(sub);
            cout << "Got a packet: " << smsg << endl;
        }
        if(items[1].revents & ZMQ_POLLIN){
            heart.recv(&msg);
            cout << "Got a heartbeat back!" << endl;
            gotMilk = true;
        }
        cout << ':';
        sleep(1);
    }
    catch(zmq::error_t e){
        cout << "Got an error" << endl;
        cout << e.what() << endl;
        return 1;
    }
    }
    return 0;

}
