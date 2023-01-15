#include "CommandOne.h"
#include "Command.h"
//#include "stdio.h"
//#include "iostream"
//#include <string>
//#include <fstream>
//using namespace std;
//
//class CommandOne : public Command{
//public:
//    string filePath;
//    void execute(){
//        ifstream file;
//        string fp;
//
///        cout << "Please upload your local train CSV file." << endl;
///        getline(cin, filePath);
///        this->dio.write("Please upload your local train CSV file.");
//        fp = this->dio.read();
//
//        file.open(fp);
//
//        if(!file) {
//            //cout << "invalid input" << endl;
//            this->dio.write("invalid input");
//            return;
//        } else {
//            this->filePath = fp;
//            this->dio.write("Upload complete.");
//        }
//        file.close();
//
///        cout << "Please upload your local test CSV file." << endl;
///        getline(cin, filePath);
//        this->dio.write("Please upload your local test CSV file.");
//        fp = this->dio.read();
//
//        file.open(fp);
//
//        if(!file) {
///            cout << "invalid input" << endl;
//            this->dio.write("invalid input");
//            file.close();
//            return;
//        } else {
///            cout << "Upload complete." << endl;
//            this->filePath = fp;
//            this->dio.write("Upload complete.");
//        }
//        file.close();
//
//    }
//
//    CommandOne(string des, DefaultIO dio1): Command(des, dio1) {
//        this->description = "upload an unclassified csv data file";
//        this->filePath = '\0';
//    }
//};
