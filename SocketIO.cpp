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
            close(other_sock);
            return nullptr;
        }
        if (read_bytes < 0) {
            close(other_sock);
            cout << "error reading message" << endl;
            return nullptr;
        }
    }
    else {
        char temp[4096];
        strncpy(temp, recv_buffer + offset + 1, 4095 - offset);
        strncpy(recv_buffer, temp, 4095 - offset);
        int read_bytes = recv(other_sock, recv_buffer + 4095-offset, offset+1, 0);
        if (read_bytes == 0) {
            close(other_sock);
            return nullptr;
        }
        if (read_bytes < 0) {
            close(other_sock);
            cout << "error reading message" << endl;
            return nullptr;
        }
    }

    offset = 0;
    while (offset < 4096) {
        if (recv_buffer[offset] == '\n'){
            break;
        }
        ++offset;
    }
    if(offset >= 4096) {
        throw new exception;
    }

    string s(recv_buffer);
    return s;
}

void SocketIO::write(string string) {
    int sent_bytes = send(other_sock, string.c_str(), string.length(), 0);
    if (sent_bytes < 0) {
        cout << "error sending to client" << endl;
        close(other_sock);
    }
    return;
}

SocketIO::SocketIO(int other_sock){
    this->other_sock = other_sock;
    this->offset = 0;
    memset(recv_buffer, '\0', sizeof(recv_buffer));
    this->initialized = false;

}
