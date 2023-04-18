#include <iostream>
#include <cstdlib>
#include "sshdMonitorHelper.h"
using namespace std;

class reportGen
{
    public:
        reportGen();

        //Report generation
        void generateDailyReport();
        void generateWeeklyReport();
        void generateMonthlyReport();

        int writeCurrentMonth();
        int writeLatestRecord(string path);

        string readCurrentMonth();
        string readLatestRecord(string path);


    private: 
        string MONTH_PATH;
   
};