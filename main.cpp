#include <iostream>
#include "global.h"
#include <stdlib.h>
#include "primer.h"
using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cerr<<"argc must be 2"<<endl;
        return -1;
    }

    string cfgfile = argv[1];

    if (Parse(cfgfile)) {
        cerr<< "parse config file " << cfgfile << " failed!\n";
        return -1;
    }

    srand((unsigned)time(NULL));


    Generate_primer generatePrimer;
    generatePrimer.Generate_all_qulified_primers();




/*
    fstream payload_file;
    payload_file.open("./payload",ios::out);
    for (int j = 0; j < g_payload_num; ++j) {
        string acc = "payload";
        acc += to_string(j);
        payload_file<<acc<<endl;
        string data;
        for (int i = 0; i < g_payload_length; ++i) {
            data+=nuleotides[rand()%4];
        }
        payload_file<<data<<endl;
    }
    payload_file.close();*/


    return 0;
}