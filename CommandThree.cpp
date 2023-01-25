#include "CommandThree.h"
#include "Command.h"
#include "DefaultIO.h"
#include <string>
#include <fstream>
#include <filesystem>
#include "CanberraDistance.h"
#include "ChebyshevDistance.h"
#include "MinkowskiDistance.h"
#include "EuclidianDistance.h"
#include "ManhattanDistance.h"
#include "StrToVector.h"
#include "IfstreamToMap.h"
#include "Distance.h"
#include "KNN.h"
#include <vector>
#include <iostream>
#include "string.h"
#include <stdio.h>
#include <list>
#include <map>
#include <cstring>

void CommandThree::execute() {

    *testResults = "";

    if(*train == "" || *test == "") {
        this->getDio().write("please upload data");
        return;
    }
    string line;
    istringstream testStream(*test);
    int j = 1;
    while(getline(testStream,line)){
        vector<string> vecStr = StrToVector::strToVector(line, ',');
        int vecLength = vecStr.size() - 1;
        vector<double> doubleVec;
        int i;
        for (i = 0; i < vecLength; ++i) {
            try {
                double d = stod(vecStr[i]);
                doubleVec.push_back(d);
            }
            catch (exception e) {
                this->getDio().write("invalid input");
                return;
            }
        }

        map<vector<double>, string> vecMap;
        vecMap = IfstreamToMap::ifstreamToMap(*(this->train), vecLength);
        //If there are no valid vectors to compare distance with, it's an error.
        if (vecMap.size() == 0) {
            this->getDio().write("vector doesnt not match the training set");
            return;
        }
        int tempK = *(this->k);
        if (vecMap.size() < tempK) {
            tempK = vecMap.size();
        }

        list<vector<double>> KDistanceList;
        //Get the list of the K closest neighbors
        KDistanceList = KNN::knnList(doubleVec, *(this->distance), vecMap, tempK);
        string maxType;
        maxType = KNN::findVectorType(KDistanceList, vecMap);
        *testResults += j;
        *testResults += "   ";
        *testResults += maxType;
        *testResults += '\n';
        j++;
    }
    *testResults += "Done.";
    
    this->getDio().write("classifying data complete");
    return;
}

CommandThree::CommandThree(DefaultIO dio, int* k, Distance** dis,
                           string* train, string* test, string* testResults): Command("3. classify data", dio) {
    this->k = k;
    this->distance = dis;
    this->train = train;
    this->test = test;
    this->testResults = testResults;
}