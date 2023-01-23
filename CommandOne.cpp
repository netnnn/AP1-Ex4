#include "CommandOne.h"
#include "Command.h"
#include <filesystem>
#include <fstream>
#include <iostream>

bool copyFile(string src, string dst) {
    string line;
    // For writing text file
    // Creating ofstream & ifstream class object
    ifstream ini_file{src}; // This is the original file
    ofstream out_file{ dst };
    if (ini_file && out_file) {
        try {

            while (getline(ini_file, line)) {
                out_file << line << "\n";
            }

        } catch (exception e) {
            ini_file.close();
            out_file.close();
            return false; //return there's an error.
        }
        ini_file.close();
        out_file.close();
        return true; //return upload completed.
    }
    else {
        ini_file.close();
        out_file.close();
        return false; //return there's an error.
    }
}


void CommandOne::execute(){
    ifstream file;
    string fp;

    this->getDio().write("Please upload your local train CSV file.");
    fp = this->getDio().read();

    file.open(fp);

    if(!file) {
        this->getDio().write("invalid input");
        file.close();
        return;
    } else {
        string dst = "trainVectors.csv";
        if (copyFile(fp, dst)) {
            this->trainPath = dst;
            this->getDio().write("Upload complete.");
        } else {
            this->getDio().write("invalid input");
            file.close();
            return;
        }
    }
    file.close();

    this->getDio().write("Please upload your local test CSV file.");
    fp = this->getDio().read();

    file.open(fp);

    if(!file) {
        this->getDio().write("invalid input");
        file.close();
        return;
    } else {
        string dst = "testVectors.csv";
        if (copyFile(fp, dst)) {
            this->localPath = dst;
            this->getDio().write("Upload complete.");
        } else {
            this->getDio().write("invalid input");
            file.close();
            return;
        }
    }
    file.close();
    return;
}

CommandOne::CommandOne(string des, DefaultIO dio1): Command(des, dio1) {}