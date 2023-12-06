#ifndef DAY5_H
#define DAY5_H

#include <string>

namespace DayFive
{
    struct mapPart
    {
        unsigned long long start;
        unsigned long long end;
        unsigned long long change;
    };

    struct startingSeeds
    {
        unsigned long long start;
        unsigned long long end;
    };

    void part1();
    void part2();
    mapPart getValues(std::string line);
}


#endif