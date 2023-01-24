#include "Command.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include "CommandTwo.h"
#include "string"
#include "string.h"

#include "CanberraDistance.h"
#include "ChebyshevDistance.h"
#include "MinkowskiDistance.h"
#include "EuclidianDistance.h"
#include "ManhattanDistance.h"
#include "StrToVector.h"
#include "IfstreamToMap.h"
#include "Distance.h"


void CommandTwo::execute() {
    bool kIsValid = true;
    bool disIsValid = true;
    string kStr = to_string(this->k);
    string printKData = "The current KNN parameters are: K = " + kStr;
    string printDisData = ", distance metric = " + this->disString;
    this->getDio().write(printKData + printDisData);

    string userInput = this->getDio().read();
    if (userInput == "") {
        return;
    }
    vector<string> allStr;
    char* char_array = new char[userInput.length() + 1];

    // make sure that the new string is null terminated
    char_array[userInput.length()] = '\0';

    for (int i = 0; i < userInput.length(); i++) {
        char_array[i] = userInput[i];
    }

    char* ptr;
    //Converting the line seperated by spaces to a vector.
    ptr = strtok(char_array, " ");
    while (ptr != NULL) {
        allStr.emplace_back(ptr);
        ptr = strtok (NULL, " ");
    }

    if (allStr.size() != 2) {
        this->getDio().write("invalid number of arguments\n");
        return;
    }
    string temp;
    temp = allStr.back();
    const char *userDis = temp.c_str();

    //Then, the last string in the vector is the K.
    allStr.pop_back();
    temp = allStr.back();
    int userK;
    try {
        userK = stoi(temp);
    }
    catch (exception e) {
        kIsValid = false;
    }
    if (userK <= 0) {
        kIsValid = false;
    }


    Distance *x;
    string disTempStr;
    if (strcmp("MAN", userDis) == 0 || strcmp("AUC", userDis) == 0
    || strcmp("CAN", userDis) == 0 || strcmp("CHB", userDis) == 0 || strcmp("MIN", userDis) == 0) {
        if (strcmp("MAN", userDis) == 0) {
            x = new ManhattanDistance;
            disTempStr = "MAN";
        }
        else if (strcmp("AUC", userDis) == 0){
            x = new EuclidianDistance;
            disTempStr = "AUC";
        }
        else if (strcmp("CAN", userDis) == 0){
            x = new CanberraDistance;
            disTempStr = "CAN";
        }
        else if (strcmp("CHB", userDis) == 0){
            x = new ChebyshevDistance;
            disTempStr = "CHB";
        }
        else if (strcmp("MIN", userDis) == 0){
            x = new MinkowskiDistance;
            disTempStr = "MIN";
        }
        disIsValid = true;
    }
    //If no such distance, its invalid.
    else {
        disIsValid = false;
    }

    if (!kIsValid){
        this->getDio().write("invalid value for K\n");
    }
    if (!disIsValid){
        this->getDio().write("invalid value for metric\n");
    }
    if (kIsValid && disIsValid){
        this->k = userK;
        this->distance = x;
        this->disString = disTempStr;
        return;
    }

    return;

}

CommandTwo::CommandTwo(DefaultIO dio): Command("2. algorithm settings", dio) {};