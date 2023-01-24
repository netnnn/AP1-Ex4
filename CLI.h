#ifndef CLI_H
#define CLI_H
#include "Command.h"
#include "CommandOne.h"
#include "CommandTwo.h"
#include "CommandThree.h"
#include "CommandFour.h"
#include "CommandFive.h"
#include <vector>
#include <string>
using namespace std;

class CLI{
private:
    DefaultIO dio;
    vector<Command> cmdList;
public:
    void start();

    CLI(DefaultIO dio, CommandOne cmd1, CommandTwo cmd2, CommandThree cmd3, CommandFour cmd4, CommandFive cmd5);
};

#endif
