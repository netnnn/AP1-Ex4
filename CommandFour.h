#ifndef AP1_EX4_COMMANDFOUR_H
#define AP1_EX4_COMMANDFOUR_H
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

class CommandFour : public Command{
    private:
        string* train;
        string* test;
        string* testResults;

    public:
        void execute();

        CommandFour(DefaultIO dio, string* train, string* test, string* testResults);

};

#endif //AP1_EX4_COMMANDFOUR_H
