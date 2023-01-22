#ifndef AP1_EX4_COMMAND_H
#define AP1_EX4_COMMAND_H
#include "DefaultIO.h"
#include "string"
using namespace std;

class Command {
private:
    string description;
    DefaultIO dio;
public:
    virtual void execute();

    Command(string des, DefaultIO dio1);

    void setDescription(string des);

    string getDescription();

    void setDio(DefaultIO dio1);

    DefaultIO getDio();
};

#endif //AP1_EX4_COMMAND_H
