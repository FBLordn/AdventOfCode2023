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

    static std::map<char, int> conversion1 = {{'A', 12}, {'K', 11}, {'Q', 10}, {'J', 9}, {'T', 8}, {'9', 7}, {'8', 6}, {'7', 5}, {'6', 4}, {'5', 3}, {'4', 2}, {'3', 1}, {'2', 0}};
    static std::map<char, int> conversion2 = {{'A', 13}, {'K', 12}, {'Q', 11}, {'T', 10}, {'9', 9}, {'8', 8}, {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}, {'J', 1}};
    
    void part1();
    void part2();
    unsigned long getWorth1(std::string cards);    
    unsigned long getWorth2(std::string cards);    
}

#endif 