#include <iostream>
#include <cstdlib>
#include "sshdMonitorHelper.h"
using namespace std;

class reportGen
{
    public:
        reportGen();

        int writeCurrentMonth();
        void writeLatestRecord();

        string readLatestRecord();
        string readCurrentMonth();

        //Report generation
        void generateDailyReport();
        void generateWeeklyReport();
        void generateMonthlyReport();

    private: 
        string LAST_RECORD_PATH;
   
};