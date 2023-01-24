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
    ifstream file;
    file.open(this->trainPath);
    if(!file) {
        this->getDio().write("please upload data");
        file.close();
        return;
    }
    string line1;
    getline(file,line1);
    vector<string> vecStr = StrToVector::strToVector(line1, ',');
    int vecLength = vecStr.size() - 1;
    file.close();

    map<vector<double>, string> vecMap;
    vecMap = IfstreamToMap::ifstreamToMap(this->trainPath, vecLength);
    //If there are no valid vectors to compare distance with, it's an error.
    if (vecMap.size() == 0) {
        this->getDio().write("please upload data");
        return;
    }
    int tempK = this->k;
    if (vecMap.size() < tempK) {
        tempK = vecMap.size();
    }


    file.open(this->localPath);
    if(!file) {
        this->getDio().write("please upload data");
        file.close();
        return;
    }
    string line;
    vector<string> vecTypes;
    vector<int> lineNums;
    int j = -1;
    while(getline(file,line)){
        vector<string> vec = StrToVector::strToVector(line, ',');
        vector<double> doubleVec;
        int i;
        for (i = 0; i < vecLength; ++i) {
            try {
                double d = stod(vecStr[i]);
                doubleVec.push_back(d);
            }
            catch (exception e) {
                break;
            }
        }
        j++;
        if (i != vecLength) continue;

        list<vector<double>> KDistanceList;
        //Get the list of the K closest neighbors
        KDistanceList = KNN::knnList(doubleVec, this->distance, vecMap, tempK);

        string maxType;
        maxType = KNN::findVectorType(KDistanceList, vecMap);
        vecTypes.push_back(maxType);
        lineNums.push_back(j);
    }
    this->vectorTypes = vecTypes;
    this->linesNumber = lineNums;
    this->getDio().write("classifying data complete");
    file.close();
    return;
}

CommandThree::CommandThree(DefaultIO dio, int k, Distance* dis,
                           string train, string local): Command("3. classify data", dio) {
    this->k = k;
    this->distance = dis;
    this->trainPath = train;
    this->localPath = local;
}