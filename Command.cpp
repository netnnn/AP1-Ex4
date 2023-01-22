#include "Command.h"
#include "DefaultIO.h"
#include "string"
using namespace std;

void Command::execute() {
    return;
}

Command::Command(string des, DefaultIO dio1){
    this->description = des;
    this->dio = dio1;
}

void Command::setDescription(string des) {
    this->description = des;
}

string Command::getDescription() {
    return this->description;
}

void Command::setDio(DefaultIO dio1){
    this->dio = dio1;
}

DefaultIO Command::getDio() {
    return this->dio;
}
