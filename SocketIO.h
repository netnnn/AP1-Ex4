#ifndef AP1_EX4_SOCKETIO_H
#define AP1_EX4_SOCKETIO_H
using namespace std;
#include "DefaultIO.h"
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class SocketIO : public DefaultIO{
    private:
        bool initialized;
        int offset;
        int other_sock;
        char recv_buffer[4096];

    public:
        string read();
        void write(string string);
        SocketIO(int other_sock);
};


#endif
