//
// Created by Wei00161@umn.edu on 2020/8/23.
//

#ifndef SEQUENCE_PRODUCER_PRIMER_H
#define SEQUENCE_PRODUCER_PRIMER_H

#include <random>
#include "global.h"
#include <unordered_set>
static const string nuleotides[] = { "A", "T", "G", "C" };


class Generate_primer{
public:
    Generate_primer()= default;
    ~Generate_primer()= default;
    void Generate_all_qulified_primers();
    bool GC_content();
    bool SelfComplementary();
    bool CrossComplementary();
    bool Homopolymers();
    bool HammingDistance();
    bool Temperature();
    bool Verification();




    string primer_ID;
    void ReGenerateNewID();

    vector<string> qualified_primers_;
    unordered_set<string> substrs_of_all_primers_;
};

#endif //SEQUENCE_PRODUCER_PRIMER_H
