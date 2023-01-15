#ifndef AP1_EX4_COMMAND_H
#define AP1_EX4_COMMAND_H
#include "DefaultIO.h"
#include "string"
using namespace std;

class Command {
public:
    string description;
    DefaultIO dio;

    virtual void execute();

    Command(string des, DefaultIO dio1){
        this->description = des;
        this->dio = dio1;
    }

    void setDescription(string des) {
        this->description = des;
    }

    void setDio(DefaultIO dio1){
        this->dio = dio1;
    }
};

#endif //AP1_EX4_COMMAND_H
