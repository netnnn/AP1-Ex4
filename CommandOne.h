#ifndef AP1_EX4_COMMANDONE_H
#define AP1_EX4_COMMANDONE_H
using namespace std;
#include "Command.h"
#include "DefaultIO.h"
#include <string>
using namespace std;

class CommandOne : public Command{
public:
    void execute();

    CommandOne(string des, DefaultIO dio1);
};

#endif //AP1_EX4_COMMANDONE_H
