//
// Created by johnnie on 19/01/2020.
//

#include "MyParallelServer.h"
extern int countClient;

int MyParallelServer::open(int port, ClientHandler *c) {
    int addrlen = sizeof(address);
    m_socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socketFd == -1) {
        //error
        cerr<<"could not create a socket"<<endl;
        return -1;
    }
    //bind socket to IP address
    //we first create the socketAddress obj.
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");//give me any IP allocated for my machine.
    address.sin_port = htons(port);
    //we need to convert our number
    //to a number that the network understands

    //the actual bind command
    if (bind(m_socketFd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr<<"could not bind socket to an IP"<<endl;
        return -1;
    }

    if (listen(m_socketFd, 1) == -1) {
        cerr<<"Error during listening command"<<endl;
    }
    isConnect = true;
    while (isConnect) {
        struct timeval tv{};
        tv.tv_sec = 130;
        setsockopt(m_socketFd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
        int client_socket = accept(m_socketFd, (struct sockaddr *) &address, (socklen_t*)&addrlen);

        if(client_socket == -1 && countClient==0) {
            break;
        }
        else {
            countClient ++;
            cout<<"new client"<<endl;
            thread* t = new thread(&ClientHandler::handleClient, c, client_socket, client_socket);
            this_thread::sleep_for(chrono::seconds(1s));
            //t->join();
        }
    }
    return 0;
}

void MyParallelServer::stop() {
    isConnect = false;
    cout<<"timeout"<<endl;
    close(m_socketFd);
}
