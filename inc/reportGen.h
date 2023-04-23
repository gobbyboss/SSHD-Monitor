#include <iostream>
#include <cstdlib>
#include <stack>
#include "sshdMonitorHelper.h"
using namespace std;

class reportGen
{
    public:
        reportGen(string status);

        void writeLatestRecord();
        void loadStatusFile();
        string readLatestRecord();
        string readCurrentMonth();
        string readCurrentDay();

        //Report generation
        void generateDailyReport();
        void generateMonthlyReport();

    private: 
        string RECORD_PATH, STATUS;
        stack<string> statusdata; 
};