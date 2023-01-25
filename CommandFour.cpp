#include "CommandFour.h"
#include "Command.h"
#include "DefaultIO.h"
#include <string>
#include <vector>

void CommandFour::execute() {
    if(*train == "") {
        this->getDio().write("please upload data\n");
        return;
    }

    if(*test == "") {
        this->getDio().write("please upload data\n");
        return;
    }

    if (*testResults == "") {
        this->getDio().write("please classify the data\n");
        return;
    }

    this->getDio().write(*testResults + "Done.\n");
    return;
}

CommandFour::CommandFour(DefaultIO dio, string* train, string* test, string* testResults): Command("4. display results\n", dio){
    this->train = train;
    this->test = test;
    this->testResults = testResults;
};
