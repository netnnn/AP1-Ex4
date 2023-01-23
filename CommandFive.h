#ifndef AP1_EX4_COMMANDFIVE_H
#define AP1_EX4_COMMANDFIVE_H
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


class CommandFive : public Command{
public:
    string trainPath;
    string localPath;
    vector<string> vectorTypes;
    vector<int> linesNumbers;
    string path;

    void execute();

    CommandFive(string des, DefaultIO dio1, string train, string local, vector<string> type, vector<int> lines);

};

#endif //AP1_EX4_COMMANDFIVE_H
