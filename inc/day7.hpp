#ifndef DAY7_H
#define DAY7_H

#include <string>
#include <map>

namespace DaySeven
{
    struct hand
    {
        std::string cards;
        int bid;
        unsigned long worth;
    };

    static std::map<char, int> conversion1 = {{'A', 12}, {'K', 11}, {'Q', 10}, {'J', 9}, {'T', 8}};
    static std::map<char, int> conversion2 = {{'A', 13}, {'K', 12}, {'Q', 11}, {'T', 10}, {'J', 1}};
    
    void part1();
    void part2();
    bool compareLength(const hand& a, const hand& b);
    unsigned long getWorth1(std::string cards);    
    unsigned long getWorth2(std::string cards);    
}

#endif 