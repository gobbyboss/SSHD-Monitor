#include "../inc/reportStager.h"

int main()
{
    reportStager gen("Failed");
    gen.processStatusFile();
    reportStager gen2("Accepted");
    gen2.processStatusFile();
    return 0;
}