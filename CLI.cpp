#include "CLI.h"
#include <vector>
#include <string>
using namespace std;

CLI::CLI(DefaultIO dio, CommandOne cmd1, CommandTwo cmd2, CommandThree cmd3,CommandFour cmd4,CommandFive cmd5){
    this->dio = dio;
    cmdList.push_back(cmd1);
    cmdList.push_back(cmd2);
    cmdList.push_back(cmd3);
    cmdList.push_back(cmd4);
    cmdList.push_back(cmd5);
}

void CLI::start(){
    while(true) {
        string message = "Welcome to the KNN Classifier Server. Please choose an option:\n";
        for (Command cmd : cmdList) {
            message.append(cmd.getDescription());
        }
        this->dio.write(message);

        string choice = this->dio.read();

        if(choice == "1") {
            cmdList[0].execute();
        } else if (choice == "2") {
            cmdList[1].execute();
        } else if (choice == "3") {
            cmdList[2].execute();
        } else if (choice == "4") {
            cmdList[3].execute();
        } else if (choice == "5") {
            //new thread
            cmdList[4].execute();
        }
    }
}

