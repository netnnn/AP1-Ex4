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
public:
    int k;
    Distance* distance;
    string trainPath;
    string localPath;



    void execute();

    CommandThree(string des, DefaultIO dio1, int k1, Distance* dis, string train, string local);

};

#endif //AP1_EX4_COMMANDTHREE_H
