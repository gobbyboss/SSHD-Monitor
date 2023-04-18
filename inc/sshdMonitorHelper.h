#ifndef SSHDMONITORHELPER_H
#define SSHDMONITORHELPER_H

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

struct {
        string STATUS;
        string* data;
} ipDataStruct;

//Function Prototypes
int getFileLineCount(string path);
int getFileSize(string path);

string getIPFromString(string rawString);
string getMonthFromString(string rawString);
string* fileToStringArr(string path);



#endif