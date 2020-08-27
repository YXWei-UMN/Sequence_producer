//
// Created by wyx on 19-6-20.
//

#include "global.h"

int g_primer_length;
int g_payload_length;
int g_primer_num;
int g_payload_num;
double g_GC_content_lower_bound;
double g_GC_content_upper_bound;
int g_length_of_selfcomplementary;
int g_length_of_crosscomplementary;
int g_length_of_homopolymers;
int g_minimum_hamming_distance;
int g_temperature_lower_bound;
int g_temperature_upper_bound;
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
            case hash_("GC_content_lower_bound"):
                g_GC_content_lower_bound = stod(value);
                break;
            case hash_("GC_content_upper_bound"):
                g_GC_content_upper_bound = stod(value);
                break;
            case hash_("length_of_homopolymers"):
                g_length_of_homopolymers = stoi(value);
                break;
            case hash_("length_of_selfcomplementary"):
                g_length_of_selfcomplementary = stoi(value);
                break;
            case hash_("length_of_crosscomplementary"):
                g_length_of_crosscomplementary = stoi(value);
                break;
            case hash_("minimum_hamming_distance"):
                g_minimum_hamming_distance = stoi(value);
                break;
            case hash_("temperature_lower_bound"):
                g_temperature_lower_bound = stoi(value);
                break;
            case hash_("temperature_upper_bound"):
                g_temperature_upper_bound = stoi(value);
                break;
            default:
                cout<<"unknown cfg: "<<key<<endl;
                return -1;
        }
    }
    return 0;
}
