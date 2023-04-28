#include "../inc/reportStager.h"

reportStager::reportStager(string status)
{
    CACHE_PATH = "/var/cache/sshdmonitor/";
    TMP_PATH = "/var/tmp/sshdmonitor/";
    STATUS = status;
}

void reportStager::writeSingleRecord(string path, string record)
{
    ofstream file;
    file.open(path);
    if(file.is_open())
    {
        file << record;
        file.close();
    }
    else
    {
        cout << "Could not access " << path << ". Exiting now..";
        exit(EXIT_FAILURE);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: Reads the first line of the file on a given path
// 
// Parameters:  string - path: The path of the file to be read
// 
// Returns:     string - line: The record read from the LAST_RECORD file          
/////////////////////////////////////////////////////////////////////////////////////////////////////
string reportStager::readSingleRecord(string path)
{
    string line;
    ifstream lastRecord(path);
    if(lastRecord.is_open())
    {
        getline(lastRecord, line);
        return line;
    }
    else
    {       
        cout << "Failed accessing " << path << "\n\nExiting now...\n";
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
void reportStager::loadStatusFile()
{
    string line;
    ifstream data(CACHE_PATH + STATUS);
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

void reportStager::processStatusFile()
{
    string path = TMP_PATH + STATUS;
    string lastStatusPath = path + "_LastRecord";
    string statusDataPath = path + "_Data";
    
    loadStatusFile();

    ifstream infile(lastStatusPath);
    if(infile.good())
    {
        cout << readSingleRecord(path);
    }
    else
    {
        string ip;
        while(!statusdata.empty())
        {
            getIPFromString(statusdata.top(), ip);
            string command = "curl ipinfo.io/" + ip + " >> " + statusDataPath;
            system(command.c_str()); 
            statusdata.pop();
        }
    }
}