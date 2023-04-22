#include <iostream>
#include <cstdlib>
#include "sshdMonitorHelper.h"
using namespace std;

class reportGen
{
    public:
        reportGen(string status);

        void writeLatestRecord();

        string readLatestRecord();
        string readCurrentMonth();
        string readCurrentDay();

        //Report generation
        void generateDailyReport();
        void generateMonthlyReport();

    private: 
        string LAST_RECORD_PATH, STATUS;
};