#ifndef SSHDMONITORHELPER_H
#define SSHDMONITORHELPER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <regex>
using namespace std;

//Function Prototypes
int getFileLineCount(string path);
int getFileSize(string path);

void getMonthFromString(string rawString, string &month);
void getDayFromString(string rawString, string &day);
string* fileToStringArr(string path);
string getIPFromString(string rawString, string &ip);


#endif