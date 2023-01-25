#include "CLI.h"
#include <vector>
#include <string>
#include <thread>
#include "CommandOne.h"
#include "CommandTwo.h"
#include "CommandThree.h"
#include "CommandFour.h"
#include "CommandFive.h"
#include <unistd.h>
using namespace std;

CLI::CLI(DefaultIO dio, int socknumber){
    this->socknumber = socknumber;
    this->dio = dio;
    CommandOne cmd1(dio, &train, &test);
    CommandTwo cmd2(dio, &k, &disString, &distance);
    CommandThree cmd3(dio, &k, &distance, &train, &test, &testResults);
    CommandFour cmd4(dio, &train, &test, &testResults);
    CommandFive cmd5(dio, &train, &test, &testResults);
    cmdList.push_back(cmd1);
    cmdList.push_back(cmd2);
    cmdList.push_back(cmd3);
    cmdList.push_back(cmd4);
    cmdList.push_back(cmd5);

    this->k = 5;
    this->disString = "AUC";
    this->distance = new EuclidianDistance();
    this->test = "";
    this->train = "";
    this->testResults = "";
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
            cmdList[4].execute();
        } else if (choice == "8") {
            close(socknumber);
            return;
        }
    }
}

