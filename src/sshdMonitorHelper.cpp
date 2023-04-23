#include "../inc/sshdMonitorHelper.h"
int getFileLineCount(string path)
{
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Finds month in journalctl sshd log string and sets the referenced month variable to it
// 
// Parameters:  string rawString - An ACCEPTED or FAILED line as a string from the journalctl sshd log
//              string &month    - An empty month string to be passed by reference
// 
// Returns:     None.           
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
// Description: Finds day in journalctl sshd log string and sets the referenced day variable to it
// 
// Parameters:  string rawString - An ACCEPTED or FAILED line as a string from the journalctl sshd log
//              string &day    - An empty day string to be passed by reference
// 
// Returns:     None.           
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

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Detirmines whether the neighboring characters at a given index in a string are digits
// 
// Parameters:  string str     - Any string
//              int index      - The index in the string to check the neighbors of 
// 
// Returns:     true           - If neighbors are digits
//              false          - If one or two neighbors are not digits           
/////////////////////////////////////////////////////////////////////////////////////////////////////
bool neighborIsDigit(string str, int index)
{
    return isdigit(str[index - 1]) && isdigit(str[index + 1]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Finds IP in journalctl sshd log string and sets the referenced day variable to it
// 
// Parameters:  string rawString - An ACCEPTED or FAILED line as a string from the journalctl sshd log
//              string &ip       - An empty IP string to be passed by reference
// 
// Returns:     None. 
//
// Notes:       This function does not completeley validate an IP, but rather checks if the string
//              subsequence is all digits and decimals, along with validating specifically 3 decimals
//              with leading and trailing digits.  
/////////////////////////////////////////////////////////////////////////////////////////////////////
void getIPFromString(string rawString, string &ip)
{
    int index = 0;
    int start = 0;
    bool valid = false;
    while(index < rawString.length() && !valid)
    {
        if(isdigit(rawString[index]))
        {
            int numDecimals = 0;
            bool foundPotentialIP = false;
            start = index;
            while(!foundPotentialIP)
            {
                if(!isdigit(rawString[index]) && rawString[index] != '.')
                {
                    foundPotentialIP = true;
                }
                if(rawString[index] == '.' && neighborIsDigit(rawString, index))
                {
                    numDecimals++;
                }
                index++;
            }
            if(numDecimals == 3)
            {
                ip = "";
                int end = index - 1;
                while(start < end)
                {
                    ip += rawString[start];
                    start++;
                }
                valid = true;
            }
        }
        index++;
    }
    
}
