#ifndef AP1_EX4_COMMANDONE_H
#define AP1_EX4_COMMANDONE_H
using namespace std;
#include "Command.h"
#include "DefaultIO.h"
#include <string>
#include <fstream>

using namespace std;

class CommandOne : public Command{
private:
    string* train;
    string* test;
public:
    void execute();

    CommandOne(DefaultIO dio, string* train, string* test);
};

#endif //AP1_EX4_COMMANDONE_H
