//
// Created by wyx on 19-6-20.
//

#include "global.h"

int g_primer_length;
int g_payload_length;
int g_primer_num;
int g_payload_num;

int Parse(string cfgfile){
    ifstream filestream(cfgfile, ios_base::in);
    if (filestream.fail()) {
        cerr << "open cfgfile:" << cfgfile << " fails!\n";
        return -1;
    }
    string line;

    while(getline(filestream, line)) {
        if (line.size()<=1 || line[0]== '#')
            continue;

        stringstream ss(line);
        string key, value;
        getline(ss, key, ' ');
        getline(ss, value, ' ');

        switch(hash_(key.c_str())){
            case hash_("primer_length"):
                g_primer_length = stoi(value);
                break;
            case hash_("payload_length"):
                g_payload_length = stoi(value);
                break;
            case hash_("primer_num"):
                g_primer_num = stoi(value);
                break;
            case hash_("payload_num"):
                g_payload_num = stoi(value);
                break;
            default:
                cout<<"unknown cfg: "<<key<<endl;
                return -1;
        }
    }
    return 0;
}
