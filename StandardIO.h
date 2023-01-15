//
// Created by evias on 15/01/2023.
//
#include "string"
#include "DefaultIO.h"
#ifndef AP1_EX4_STANDARDIO_H
#define AP1_EX4_STANDARDIO_H

using namespace std;
class StandardIO : public DefaultIO{
    public:
        string read();
        void write(string str);

};

#endif //AP1_EX4_STANDARDIO_H
