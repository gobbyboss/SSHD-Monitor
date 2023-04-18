#include "../inc/reportGen.h"

reportGen::reportGen()
{
    LAST_RECORD_PATH = "/var/lib/SSHDMonitor/LAST_RECORD";
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
    string currentMonth = getMonthFromString(readLatestRecord());
    return currentMonth;
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
    cout << currentMonth << endl;
}
