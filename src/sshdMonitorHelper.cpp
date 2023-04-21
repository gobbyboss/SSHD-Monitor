#include "../inc/sshdMonitorHelper.h"
int getFileLineCount(string path)
{
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Parameters: rawString - An ACCEPTED or FAILED line as a string from the journalctl sshd log
//
// Returns:    month     - The month that the record contains           
/////////////////////////////////////////////////////////////////////////////////////////////////////
void getMonthFromString(string rawString, string &month)
{
    int index = 0;
    char check = rawString[index];
    month = "";
    while(check != ' ')
    {
        month += check;
        index++;
        check = rawString[index];
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Parameters: rawString - An ACCEPTED or FAILED line as a string from the journalctl sshd log
//
// Returns:    day       - The day that the record contains         
/////////////////////////////////////////////////////////////////////////////////////////////////////
void getDayFromString(string rawString, string &day)
{
    int index = 3; //Starts at 3 to skip month characters on the raw log string
    char check = rawString[index];
    day = "";
    while(!isdigit(check))
    {
        check = rawString[++index];
    }
    day += rawString[index];
    if(isdigit(rawString[++index]))
    {
        day += rawString[index];
    }
}

string getIPFromString(string rawString)
{
    return " ";
}
