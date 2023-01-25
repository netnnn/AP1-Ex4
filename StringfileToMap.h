#ifndef IFSTREAMTOMAP_H
#define IFSTREAMTOMAP_H

#include <map>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class StringfileToMap{
    public:
    static map<vector<double>, string> stringfileToMap(string stringfile, int vectorSize);
};

#endif