//
// Created by wyx on 19-6-20.
//

#ifndef CONFIGURABLE_DEDUP_GLOBAL_H
#define CONFIGURABLE_DEDUP_GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <ctime>
#include <cstring>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <sstream>
#include <time.h>
#include <deque>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <bitset>
#include <utility>
#include <math.h>
using namespace std;

extern int g_primer_length;
extern int g_payload_length;
extern int g_primer_num;
extern int g_payload_num;
extern double g_GC_content_lower_bound;
extern double g_GC_content_upper_bound;
extern int g_length_of_selfcomplementary;
extern int g_length_of_homopolymers;
extern int g_minimum_hamming_distance;
extern int g_temperature_lower_bound;
extern int g_temperature_upper_bound;

int Parse(string cfgfile);

typedef std::uint64_t hash_t;
constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;
constexpr hash_t hash_(char const* str, hash_t last_value = basis)
{
    return *str ? hash_(str+1, (*str ^ last_value) * prime) : last_value;
}
#endif //CONFIGURABLE_DEDUP_GLOBAL_H
