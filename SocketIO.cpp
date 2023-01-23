#include "SocketIO.h"
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
using namespace std;

string SocketIO::read() {
    if (!initialized){
        initialized = true;
        int read_bytes = recv(other_sock, recv_buffer, 4096, 0);
        if (read_bytes == 0) {
            recv_buffer[0] = '\0';
        }
        if (read_bytes < 0) {
            cout << "error reading message" << endl;
            recv_buffer[0] = '\0';
        }
    }

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
    int read_bytes = recv(other_sock, recv_buffer + 4095-i, i+1, 0);
    if (read_bytes == 0) {
        recv_buffer[0] = '\0';
    }
    if (read_bytes < 0) {
        cout << "error reading message" << endl;
        recv_buffer[0] = '\0';
    }

    return s;
}

void SocketIO::write(string string) {
    return;
}

SocketIO::SocketIO(int other_sock){
    this->other_sock = other_sock;
    memset(recv_buffer, '\0', sizeof(recv_buffer));
    this->initialized = false;

}
