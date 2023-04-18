#include "reportGen.h"

reportGen::reportGen()
{
    MONTH_PATH = "/var/lib/SSHDMonitor/currentMonth";
}

string reportGen::readLatestRecord(string path)
{
    system("grep ")
}


void reportGen::generateDailyReport()
{

}

void reportGen::generateWeeklyReport()
{

}

void reportGen::generateMonthlyReport()
{
    string currentMonth = readCurrentMonth();
    string latestMonth = readLatestRecord(MONTH_PATH);
}
