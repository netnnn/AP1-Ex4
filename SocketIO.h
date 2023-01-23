#ifndef AP1_EX4_SOCKETIO_H
#define AP1_EX4_SOCKETIO_H
using namespace std;
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class SocketIO {
    private:
    int other_sock;
    char recv_buffer[4096];

    public:
    virtual string read();
    virtual void write(string string);
    SocketIO(int other_sock);
};


#endif
