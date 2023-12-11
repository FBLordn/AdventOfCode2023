#ifndef DAY10_H
#define DAY10_H

#include <vector>
#include <string>
#include <tuple>

namespace DayTen
{
    struct pipe
    {
        char type;
        int next[2];
        char origin;
    };

    struct wall
    {
        int place;
        int first;
        int last;
    };

    void part1();
    void part2();
    pipe getPipe(int y, int x, char direction, std::vector<std::string> lines);
    std::tuple<pipe, std::string> getSecond(int y, int x, std::vector<std::string> lines);
}

#endif