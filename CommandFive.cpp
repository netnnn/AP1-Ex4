#include "CommandFive.h"
#include "Command.h"
#include "DefaultIO.h"
#include <string>
#include <filesystem>
#include <vector>
#include "thread"


void task1(vector<string> vectorTypes, vector<int> linesNumbers, DefaultIO dio, string path) {
    ofstream file(path);
    if(!file) {
        dio.write("invalid path");
        file.close();
        return;
    }

    for (int i = 0; i < vectorTypes.size(); ++i) {

        string number = to_string(linesNumbers[i]);
        string type = vectorTypes[i];
        string printNum = number + " ";

        file << printNum + type << endl;
    }

    file.close();

}

void CommandFive::execute() {
    this->path = this->getDio().read();

    ifstream file;
    file.open(this->trainPath);
    if(!file) {
        this->getDio().write("please upload data");
        file.close();
        return;
    }
    file.close();

    file.open(this->localPath);
    if(!file) {
        this->getDio().write("please upload data");
        file.close();
        return;
    }
    file.close();

    if (this->vectorTypes.size() == 0 || this->linesNumbers.size() == 0) {
        this->getDio().write("please classify the data");
        return;
    }
    thread thread(task1, this->vectorTypes, this->linesNumbers, this->getDio(), this->path);
    return;
}



CommandFive::CommandFive(DefaultIO dio, string train, string local,
                         vector<string> type, vector<int> lines): Command("5. download results", dio) {
    this->trainPath = train;
    this->localPath = local;
    this->vectorTypes = type;
    this->linesNumbers = lines;
}