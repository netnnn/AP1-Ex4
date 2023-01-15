//
// Created by evias on 15/01/2023.
//

#ifndef AP1_EX4_DEFAULTIO_H
#define AP1_EX4_DEFAULTIO_H
using namespace std;
#include "string"

class defaultIO {
    public:
    virtual string read();
    virtual void write(string string);
};


#endif //AP1_EX4_DEFAULTIO_H
