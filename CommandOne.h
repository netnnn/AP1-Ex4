#ifndef AP1_EX4_COMMANDONE_H
#define AP1_EX4_COMMANDONE_H
using namespace std;
#include "Command.h"
#include "DefaultIO.h"
#include <string>
#include <fstream>

using namespace std;

class CommandOne : public Command{
public:
    string trainPath = NULL;
    string localPath = NULL;

    void execute();

    CommandOne(DefaultIO dio);
};

#endif //AP1_EX4_COMMANDONE_H
