#ifndef AP1_EX4_COMMANDTWO_H
#define AP1_EX4_COMMANDTWO_H
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


using namespace std;

class CommandTwo : public Command{
    private:
        int* k;
        string* disString;
        Distance** distance;
    public:

        void execute();

        CommandTwo(DefaultIO dio, int* k, string* disString, Distance** distance);
};


#endif //AP1_EX4_COMMANDTWO_H
