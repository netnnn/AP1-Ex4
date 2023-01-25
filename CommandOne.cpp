#include "CommandOne.h"
#include "Command.h"
#include <filesystem>
#include <fstream>
#include <iostream>

void CommandOne::execute(){
    string line;

    this->getDio().write("Please upload your local train CSV file.");

    line = this->getDio().read();
    if(line == "") {
        cout << "invalid input" << endl;
    }

    while(line != ""){
        *train += line;
        *train += '\n';
        line = this->getDio().read();
    }

    this->getDio().write("Please upload your local test CSV file.");

    line = this->getDio().read();
    if(line == "") {
        cout << "invalid input" << endl;
    }

    while(line != ""){
        *test += line;
        *test += '\n';
        line = this->getDio().read();
    }

    return;
}

CommandOne::CommandOne(DefaultIO dio, string* train, string* test): Command("1. upload an unclassified csv data file", dio) {
    this->train = train;
    this->test = test;
}