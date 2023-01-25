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
        int k;
        string disString;
        Distance* distance;
        string train;
        string test;
        
        void choice5();
        void start();

        CLI(DefaultIO dio);
};

#endif
