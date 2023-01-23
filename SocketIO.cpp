#include "SocketIO.h"
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
using namespace std;

string SocketIO::read() {
    int read_bytes = recv(other_sock, recv_buffer, 4096, 0);

    int i = 0;
    while (i < 4096) {
        if (recv_buffer[i] == '\0'){
            break;
        }
        ++i;
    }
    if(i >= 4096) {
        throw new exception;
    }

    string s(recv_buffer);

    char temp[4096];

    strncpy(temp, recv_buffer + i + 1, 4095 - i);
    strncpy(recv_buffer, temp, 4095 - i);

    return s;
}

void SocketIO::write(string string) {
    return;
}

SocketIO::SocketIO(int other_sock){
    this->other_sock = other_sock;
    memset(recv_buffer, '\0', sizeof(recv_buffer));

}
