#include "CommandFour.h"
#include "Command.h"
#include "DefaultIO.h"
#include <string>
#include <filesystem>
#include <vector>



void CommandFour::execute() {
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

    for (int i = 0; i < this->vectorTypes.size(); ++i) {
        string number = to_string(this->linesNumbers[i]);
        string type = this->vectorTypes[i];
        string printNum = number + " ";
        //string printType = type + "\n";
        this->getDio().write(printNum + type);
    }
    this->getDio().write("Done.");
}






CommandFour::CommandFour(string des, DefaultIO dio1, string train, string local,
                         vector<string> type, vector<int> lines): Command(des, dio1) {
    this->trainPath = train;
    this->localPath = local;
    this->vectorTypes = type;
    this->linesNumbers = lines;
}
