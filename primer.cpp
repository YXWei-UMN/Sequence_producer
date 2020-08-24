//
// Created by Wei00161@umn.edu on 2020/8/23.
//

#include "primer.h"

default_random_engine e;
uniform_int_distribution<unsigned> u(0, 3);


void Generate_primer::ReGenerateNewID() {
    primer_ID.clear();
    for (int j = 0; j < g_primer_length; ++j) {
        primer_ID+=nuleotides[u(e)];
    }
}
bool Generate_primer::Verification() {
    if(!GC_content()){
        return false;
    }
    if(!Temperature()){
        return false;
    }
    if(!Homopolymers()){
        return false;
    }
    if(!SelfComplementary()){
        return false;
    }
    return HammingDistance();

}

bool Generate_primer::GC_content() {
    int GC_num = 0;
    for(auto n:primer_ID){
        if(n=='G' || n=='C') GC_num++;
    }
    double GC_proportion = GC_num/(g_primer_length*1.0);
    return !(GC_proportion > g_GC_content_upper_bound || GC_proportion < g_GC_content_lower_bound);
}

bool Generate_primer::HammingDistance() {
    for(auto n:qualified_primers_){
        int hamming_distance = 0;
        for(int i=0; i<g_primer_length; i++){
            if(primer_ID[i] != n[i]) hamming_distance++;
        }
        if(hamming_distance<g_minimum_hamming_distance) return false;
    }
    return true;
}

bool Generate_primer::Homopolymers() {
    char last_one = primer_ID[0];
    int max_length_of_homo=0;
    int cur_length_of_homo=0;

    for (int i = 1; i < g_primer_length; ++i) {
        if(primer_ID[i] == last_one) cur_length_of_homo++;
        else {
            if(cur_length_of_homo>max_length_of_homo) max_length_of_homo = cur_length_of_homo;
            cur_length_of_homo = 0;
        }
        last_one = primer_ID[i];
    }
    return max_length_of_homo < g_length_of_homopolymers;
}

bool Generate_primer::SelfComplementary() {
    unordered_set<string> all_substrs;
    for (int i = 0; i < g_primer_length-(g_length_of_selfcomplementary-1); ++i) {
        string str = primer_ID.substr(i,g_length_of_selfcomplementary);
        all_substrs.emplace(str);
        //str's complementary
        string complementary_str;
        for(auto n:str){
            switch (n){
                case 'A':{
                    complementary_str+='T';
                    break;
                }
                case 'T':{
                    complementary_str+='A';
                    break;
                }
                case 'C':{
                    complementary_str+='G';
                    break;
                }
                case 'G':{
                    complementary_str+='C';
                    break;
                }
            }
        }
        return !(all_substrs.find(complementary_str) != all_substrs.end());
    }
}

bool Generate_primer::Temperature() {
    int temp = 0;
    for(auto n:primer_ID){
        if(n=='G' || n=='C') temp+=4;
        if(n=='A' || n=='T') temp+=2;
    }
    return !(temp < g_temperature_lower_bound || temp > g_temperature_upper_bound);
}

void Generate_primer::Generate_all_qulified_primers() {
    fstream primer_file;
    primer_file.open("./primers",ios::out);
    for (int i = 0; i < g_primer_num; ++i) {
        ReGenerateNewID();
        while(!Verification()){
            ReGenerateNewID();
        }
        qualified_primers_.emplace_back(primer_ID);
        string acc = "primer";
        acc += to_string(i);
        primer_file<<acc<<endl;
        primer_file<<primer_ID<<endl;
        cout<<primer_ID<<endl;
    }
    primer_file.close();
}