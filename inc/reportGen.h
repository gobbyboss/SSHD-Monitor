#include <iostream>
#include <cstdlib>
#include "sshdMonitorHelper.h"
using namespace std;

class reportGen
{
    public:
        reportGen();

        int writeCurrentMonth();
        int writeLatestRecord();

        string readCurrentMonth();
        string readLatestRecord(string path);

        //Report generation
        void generateDailyReport();
        void generateWeeklyReport();
        void generateMonthlyReport();

    private: 
        string MONTH_PATH;
        string LAST_RECORD_PATH;
   
};