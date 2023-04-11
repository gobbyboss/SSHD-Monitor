#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string line;
    ifstream connection_info ("connection_info");
    if(connection_info.is_open())
    {  
        while(getline(connection_info, line))
        {
            if(line[0] == '-')
            {
                cout << line << '\n';
            }
        }
    }
    else
    {
        return 0;
    }
}
