#ifndef AP1_EX4_COMMANDTWO_H
#define AP1_EX4_COMMANDTWO_H
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


using namespace std;

class CommandTwo : public Command{
public:
    int k = 5;
    string disString = "AUC";
    Distance* distance = new EuclidianDistance();


    void execute();

    CommandTwo(DefaultIO dio);
};


#endif //AP1_EX4_COMMANDTWO_H
