#include "../inc/reportGen.h"

reportGen::reportGen()
{
    MONTH_PATH = "/var/lib/SSHDMonitor/CURRENT_MONTH";
    LAST_RECORD_PATH = "/var/lib/SSHDMonitor/LAST_RECORD";
}


int reportGen::writeLatestRecord()
{
    return system("journalctl -u sshd | tail -n 1 > /var/lib/SSHDMonitor/LAST_RECORD");
}

string reportGen::readLatestRecord(string path)
{
    if(reportGen::writeLatestRecord())
    {
        string line;
        ifstream lastRecord (LAST_RECORD_PATH);
        if(lastRecord.is_open())
        {
            getline(lastRecord, line);
            return line;
        }
    }
    //If the write command of the last journalctl record fails, exit
    exit(EXIT_FAILURE);
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
