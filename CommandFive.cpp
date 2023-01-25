#include "CommandFive.h"
#include "Command.h"
#include "DefaultIO.h"
#include <string>
#include <filesystem>
#include <vector>
#include <thread>

void CommandFive::execute() {
    string path = this->getDio().read();

    if(*train == "") {
        this->getDio().write("please upload data");
        return;
    }

    if(*test == "") {
        this->getDio().write("please upload data");
        return;
    }

    if (*testResults == "") {
        this->getDio().write("please classify the data");
        return;
    }
    
    this->getDio().write(*testResults);
    return;
}

CommandFive::CommandFive(DefaultIO dio, string* train, string* test, string* testResults): Command("5. download results", dio) {
    this->train = train;
    this->test = test;
    this->testResults = testResults;
}