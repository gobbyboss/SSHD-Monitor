#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include "sshdMonitorHelper.h"
using namespace std;

class reportStager
{
    public:
        reportStager(string status);
        void writeSingleRecord(string path, string record);
        void processStatusFile();
        string readSingleRecord(string path);

    private: 
        string CACHE_PATH, TMP_PATH, STATUS;
        stack<string> statusdata;
        void loadStatusFile();
};