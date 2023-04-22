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

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Reads the latest record in the journalctl sshd log
// 
// Parameters:  None.
// 
// Returns:     string - line: The record read from the LAST_RECORD file          
/////////////////////////////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Creates a string to be set to the month from the latest journalctl sshd record
// 
// Parameters:  None.
// 
// Returns:     string - month: The month read from the latest logged reccord           
/////////////////////////////////////////////////////////////////////////////////////////////////////
string reportGen::readCurrentMonth()
{
    writeLatestRecord();
    string month = "";
    getMonthFromString(readLatestRecord(), month);
    return month;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Creates a string to be set to the day from the latest journalctl sshd record
// 
// Parameters:  None.
// 
// Returns:     They day read from the latest logged reccord         
/////////////////////////////////////////////////////////////////////////////////////////////////////
string reportGen::readCurrentDay()
{
    writeLatestRecord();
    string day = "";
    getDayFromString(readLatestRecord(), day);
    return day;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Driver for the daily report 
// 
// Parameters:  None.
// 
// Returns:     None.         
/////////////////////////////////////////////////////////////////////////////////////////////////////
void reportGen::generateDailyReport()
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Driver for the monthly report 
// 
// Parameters:  None.
// 
// Returns:     None.         
/////////////////////////////////////////////////////////////////////////////////////////////////////
void reportGen::generateMonthlyReport()
{
    string currentMonth = readCurrentMonth();
    string currentDay = readCurrentDay();
    string ip = "";
    getIPFromString("Apr 14 09:47:21 arch sshd[1400468]: Accepted password for rwgoss from 76.130.218.72 port 49601 ssh2", ip);
    cout << "Success + " << ip << endl;
}
