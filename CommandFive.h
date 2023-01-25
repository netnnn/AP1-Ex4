#ifndef AP1_EX4_COMMANDFIVE_H
#define AP1_EX4_COMMANDFIVE_H
using namespace std;
#include "Command.h"
#include "DefaultIO.h"
#include <string>
#include "Distance.h"
#include "CanberraDistance.h"
#include "ChebyshevDistance.h"
#include "MinkowskiDistance.h"
#include "EuclidianDistance.h"
#include "ManhattanDistance.h"


class CommandFive : public Command{
    private:
        string* train;
        string* test;
        string* testResults;

    public:
        void execute();

        CommandFive(DefaultIO dio, string* train, string* test, string* testResults);

};

#endif //AP1_EX4_COMMANDFIVE_H
