#include "../inc/reportGen.h"

reportGen::reportGen(string status)
{
    RECORD_PATH = "/var/cache/sshdmonitor/";
    STATUS = status;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Writes the latest journalctl sshd record in the log as a text file
// 
// Parameters:  None.
// 
// Returns:     None.          
/////////////////////////////////////////////////////////////////////////////////////////////////////
void reportGen::writeLatestRecord()
{
    system("journalctl -u sshd | tail -n 1 > /var/cache/sshdmonitor/LAST_RECORD");
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
    ifstream lastRecord (RECORD_PATH + "LAST_RECORD");
    if(lastRecord.is_open())
    {
        getline(lastRecord, line);
        return line;
    }
    else
    {
        cout << "Failed accessing /var/cache/sshdmonitor/\n\nExiting now...\n";
        exit(EXIT_FAILURE);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Loads the appropriate STATUS file in /var/cache/sshdmonitor/ into the statusdata 
//              member stack 
// 
// Parameters:  None.
// 
// Returns:     None.          
/////////////////////////////////////////////////////////////////////////////////////////////////////
void reportGen::loadStatusFile()
{
    string line;
    ifstream data(RECORD_PATH + STATUS);
    if(data.is_open())
    {
        while(getline(data, line))
        {
            statusdata.push(line);
        }
    }
    else
    {
        cout << "Failed accessing /var/cache/sshdmonitor/\n\nExiting now...\n";
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
