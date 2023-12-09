#ifndef DAY8_H
#define DAY8_H

#include <string>
#include <vector>

namespace DayEight
{
    struct node
    {
        std::string name;
        std::string left;
        std::string right;
    };

    void part1();
    void part2();
    bool compareNames(const node& a, const node& b);
    node getNode(std::vector<node> paths, std::string name);
}

#endif