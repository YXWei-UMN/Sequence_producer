#include <iostream>
#include "global.h"
#include "stdlib.h"
using namespace std;

static const string nuleotides[] = { "A", "T", "G", "C" };
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

    fstream primer_file;
    primer_file.open("./primers",ios::out);
    for (int i = 0; i < g_primer_num; ++i) {
        string acc = "primer";
        acc += i;
        primer_file<<acc<<endl;
        string data;
        for (int j = 0; j < g_primer_length; ++j) {
            data+=nuleotides[rand()%4];
        }
        primer_file<<data<<endl;
    }
    primer_file.close();

    fstream payload_file;
    primer_file.open("./payload",ios::out);
    for (int j = 0; j < g_payload_num; ++j) {
        string acc = "payload";
        acc += j;
        payload_file<<acc<<endl;
        string data;
        for (int i = 0; i < g_payload_length; ++i) {
            data+=nuleotides[rand()%4];
        }
        payload_file<<data<<endl;
    }
    payload_file.close();


    return 0;
}