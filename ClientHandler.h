//
// Created by johnnie on 12/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H


class ClientHandler {
public:
    virtual void handleClient(int inputStream, int outputStream) = 0;
};


#endif //EX4_CLIENTHANDLER_H
