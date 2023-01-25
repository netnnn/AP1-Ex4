#ifndef AP1_EX4_COMMANDTHREE_H
#define AP1_EX4_COMMANDTHREE_H
using namespace std;
#include "Command.h"
#include "DefaultIO.h"
#include <string>
#include <fstream>

#include "Distance.h"

#include "CanberraDistance.h"
#include "ChebyshevDistance.h"
#include "MinkowskiDistance.h"
#include "EuclidianDistance.h"
#include "ManhattanDistance.h"


class CommandThree : public Command{
    private:
        int* k;
        Distance** distance;
        string* train;
        string* test;
        string* testResults;
        vector<string> vectorTypes;
        vector<int> linesNumber;
    public:

        void execute();

        CommandThree(DefaultIO dio, int* k, Distance** dis, string* train, string* test, string* testResults);

};

#endif //AP1_EX4_COMMANDTHREE_H
