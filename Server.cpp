#include "CanberraDistance.h"
#include "ChebyshevDistance.h"
#include "MinkowskiDistance.h"
#include "EuclidianDistance.h"
#include "ManhattanDistance.h"
#include "StrToVector.h"
#include "StringfileToMap.h"
#include "Distance.h"
#include "KNN.h"
#include <vector>
#include <iostream>
#include "string.h"
#include <stdio.h>
#include <list>
#include <map>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include "CLI.h"
#include "SocketIO.h"

using namespace std;

int main(int argv, char* args[]) {

    int port;
    //If number of arguments is different from 1 its invalid.
    if (argv != 2) {
        cout << "invalid input" << endl;
        exit(0);
    }
    //Get the arguments into variables.
    try {
        port = stoi(args[1]);
    } catch (...) {
        cout << "invalid input" << endl;
        exit(0);
    }

    if (port <= 1024 || port >= 65536) {
        cout << "invalid port value" << endl;
        exit(0);
    }

    //Creating a server socket
    const int server_port = port;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "error creating socket" << endl;
        exit(0);
    }
    //Binding the socket
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "error binding socket" << endl;
        close(sock);
        exit(0);
    }
    //Make the socket listen
    if (listen(sock, 5) < 0) {
        cout << "error listen for sockets" << endl;
        close(sock);
        exit(0);
    }
    // Endless loop which accepts a client and executes the CLI for it on a new thread
    while(true) {
        //Accept a new client
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            cout << "error accepting client" << endl;
            exit(0);
        }

        thread t(runcli, client_sock);
        t.detach();
    }

    //Close the server socket
    close(sock);
    return 0;
}

void runcli(int client_sock){
    SocketIO sockio(client_sock);
    CLI cli(sockio, client_sock);
    cli.start();
}