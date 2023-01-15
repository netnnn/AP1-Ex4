#include "StandardIO.h"
#include "DefaultIO.h"
#include <iostream>


using namespace std;
string read() {
    string line;
    getline(cin, line);
    return line;
}

void write(string str) {
    cout << str << endl;
}
