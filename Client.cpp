#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "SocketIO.h"
using namespace std;

/**
 * @brief the main method of the client: it gets the ip and port of the server in the command line arguments.
 * then,a loop which gets a line that consists of a vector, distance and k.
 * sends the line to the server, and prints its type based on the k closest neighbors or prints an error if
 * the input is invalid.
 * 
 * @param argv number of command line arguments
 * @param args the command line arguments
 * @return int 0 if the program ran successfully
 */
int main(int argv, char* args[]) {
    //if more or less than 3 command line arguments, its invalid.
    if(argv != 3) {
        cout << "invalid input" << endl;
        exit(0);
    }
    //Initializing ip address and port no.
    char* ip_address = nullptr;
    int port_no = 0;
    //getting the ip and port no. of the server.
    try{
        ip_address = args[1];
        port_no = stoi(args[2]);
    } catch (exception exception) {
        cout << "invalid input" << endl;
        exit(0);
    }
    //Making them const
    const char* c_ip_address = ip_address;
    const int c_port_no = port_no;
    //Creating a tcp socket for the client
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "error creating socket" << endl;
        exit(0);
    }
    //Connecting the client to the server socket
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(c_ip_address);
    sin.sin_port = htons(c_port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "error connecting to server" << endl;
        close(sock);
        exit(0);
    }

    SocketIO connection(sock);
    while(true){
        string serverLine = connection.read();
        while(serverLine != ""){
            cout << serverLine;
            serverLine = connection.read();
        }
        //Reading a new line from the user
        string line;
        getline(cin, line);
        connection.write(line);

        if(line == "1"){
            
        } else if(line == "2"){

        } else if(line == "3"){

        } else if(line == "4"){

        } else if(line == "5"){

        } else if(line == "8"){
            close(sock);
            break;
        } else {
            cout << "invalid input" << endl;
        }
    }
    return;
}