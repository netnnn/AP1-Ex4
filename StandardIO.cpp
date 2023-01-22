#include "StandardIO.h"
#include <iostream>
using namespace std;

string StandardIO::read() {
    string line;
    getline(cin, line);
    return line;
}

void StandardIO::write(string str) {
    cout << str << endl;
}
