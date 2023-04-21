#include "../inc/reportGen.h"

reportGen::reportGen(string status)
{
    LAST_RECORD_PATH = "/var/lib/SSHDMonitor/LAST_RECORD";
    STATUS = status;
}


void reportGen::writeLatestRecord()
{
    system("journalctl -u sshd | tail -n 1 > /var/lib/SSHDMonitor/LAST_RECORD");
}


string reportGen::readLatestRecord()
{
    string line;
    ifstream lastRecord (LAST_RECORD_PATH);
    if(lastRecord.is_open())
    {
        getline(lastRecord, line);
        return line;
    }
    else
    {
        cout << "Failed accessing /var/lib/SSHDMonitor/\n\nExiting now...\n";
        exit(EXIT_FAILURE);
    }
}

string reportGen::readCurrentMonth()
{
    writeLatestRecord();
    string month = "";
    getMonthFromString(readLatestRecord(), month);
    return month;
}

string reportGen::readCurrentDay()
{
    writeLatestRecord();
    string day = "";
    getDayFromString(readLatestRecord(), day);
    return day;
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
    string day = "";
    getDayFromString(readLatestRecord(), day);
    cout << currentMonth << " + " << day << endl;
}
