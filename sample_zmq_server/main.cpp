#include <zmq.hpp>
#include <zhelpers.hpp>
#include <iostream>
#include <sstream> 

using namespace std;

int main(int argc, char* argv[]){
    
    cout << "Welcome to a simple ZMQ server with a heartbeat REP function." << endl; 
   
    bool sendFlag = false;
    zmq::context_t context(1);
    zmq::socket_t sender (context, ZMQ_PUB);
    zmq::socket_t recver (context, ZMQ_SUB);
    zmq::socket_t hearta (context, ZMQ_REP);
    zmq::socket_t heartb (context, ZMQ_REP); 
    sender.bind("tcp://127.0.0.1:5560");
    recver.bind("tcp://127.0.0.1:5562");
    hearta.bind("tcp://127.0.0.1:5561");
    heartb.bind("tcp://127.0.0.1:5563");
    cout << "Binding success" << endl;
    recver.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    
    zmq::pollitem_t items[] = {
        { recver, 0, ZMQ_POLLIN, 0},
        { hearta, 0, ZMQ_POLLIN, 0},
        { heartb, 0, ZMQ_POLLIN, 0},   
    };
    cout << "Starting loop" << endl;
    while(1){
        cout << ".";
        zmq::message_t message;
        zmq::message_t hba;
        zmq::message_t hbb;
        zmq::poll (items, 3, 1000);
        
        if(items[0].revents & ZMQ_POLLIN){
            cout << "recver got message" << endl;
            recver.recv(&message);
        }
        if(items[1].revents & ZMQ_POLLIN){
            cout << "hearta got message" << endl;
            hearta.recv(&hba);
            s_send(hearta, "");
            sendFlag = true;
    
        }
        if(items[2].revents & ZMQ_POLLIN){
            cout << "heartb got message" << endl;
            heartb.recv(&hbb); 
            s_send(heartb, "");
            
        }
        
        if(sendFlag){
            s_send(sender, "helloworldhelelele");
            cout << "sending msg\n" ;
          
            sendFlag = false;
        }    
       
        cout << ":";
        
    }

    return 0;



}
