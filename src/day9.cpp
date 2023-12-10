#include "../inc/day9.hpp"
#include "../inc/macros.hpp"

#include <vector>
#include <string>

using namespace DayNine;


void DayNine::part1()
{
    long sum = 0;
    std::string line;
    OPEN("data/day9.txt")
    while(getline(file, line))
    {
        std::stringstream ss(line);
        std::vector<long> values;
        while(getline(ss, line, ' '))
        {
            values.push_back(std::stol(line));
        }
        for(bool allZero = true;;allZero = true)
        {
            sum += values.back();
            for(std::vector<long>::iterator i=values.begin() + 1; i != values.end(); i++)
            {
                *(i - 1) = *i - *(i - 1);
                if(*(i - 1) != 0)
                {
                    allZero = false;
                }
            }
            if(allZero)
            {
                break;
            }
            values.erase(values.end()-1);
        }
    }
    std::cout << "The sum is: " << sum << std::endl;
}


void DayNine::part2()
{
    long sum = 0;
    std::string line;
    OPEN("data/day9.txt")
    while(getline(file, line))
    {
        std::stringstream ss(line);
        std::vector<long> values;
        while(getline(ss, line, ' '))
        {
            values.push_back(std::stol(line));
        }
        bool allZero = true;
        for(bool adds=true;;adds = !adds)
        {
            if(adds)
            {
                sum += values.front();
            }
            else
            {
                sum -= values.front();
            }
            for(std::vector<long>::iterator i=values.begin() + 1; i != values.end(); i++)
            {
                *(i - 1) = *i - *(i - 1);
                if(*(i - 1) != 0)
                {
                    allZero = false;
                }
            }
            if(allZero)
            {
                break;
            }
            values.erase(values.end()-1);
            allZero = true;
        }
    }
    std::cout << "The sum is: " << sum << std::endl;
}