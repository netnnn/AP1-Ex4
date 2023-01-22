#include "CommandOne.h"
#include "Command.h"
#include <fstream>

void CommandOne::execute(){
    ifstream file;
    string fp;

    this->getDio().write("Please upload your local train CSV file.");
    fp = this->getDio().read();

    file.open(fp);

    if(!file) {
        this->getDio().write("invalid input");
        return;
    } else {
        this->getDio().write("Upload complete.");
    }
    file.close();

    this->getDio().write("Please upload your local test CSV file.");
    fp = this->getDio().read();

    file.open(fp);

    if(!file) {
        this->getDio().write("invalid input");
        return;
    } else {
        this->getDio().write("Upload complete.");
    }
    file.close();
}

CommandOne::CommandOne(string des, DefaultIO dio1): Command(des, dio1) {}