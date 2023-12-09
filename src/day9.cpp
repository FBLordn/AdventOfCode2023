#include "../inc/day9.hpp"
#include "../inc/macros.hpp"

#include <vector>
#include <string>

using namespace DayNine;

void DayNine::part1()
{
    long long sum = 0;
    std::string line;
    OPEN("data/day9.txt")
    while(getline(file, line))
    {
        std::vector<std::vector<long>> levels;
        std::stringstream ss(line);
        std::string temp;
        std::vector<long> values;
        while(getline(ss, temp, ' '))
        {
            values.push_back(std::stol(temp));
        }
        levels.push_back(values);
        for(bool allZero = false; !allZero;)
        {
            allZero = true;
            std::vector<long> nextStage;
            std::vector<long> previousStage = levels.back();
            for(int i=1; i<previousStage.size(); i++)
            {
                long change = previousStage[i] - previousStage[i-1];
                nextStage.push_back(change);
                if(change != 0)
                {
                    allZero = false;
                }   
            }
            levels.push_back(nextStage);
        }
        for(int i=levels.size()-1; i>0; i--)
        {
            levels[i-1].push_back(levels[i].back() + levels[i-1].back());
        }
        sum += levels[0].back();
    }
    //std::cout << "The sum is: " << sum << std::endl;
}

void DayNine::part2()
{
    long long sum = 0;
    std::string line;
    OPEN("data/day9.txt")
    while(getline(file, line))
    {
        std::vector<std::vector<long>> levels;
        std::stringstream ss(line);
        std::string temp;
        std::vector<long> values;
        while(getline(ss, temp, ' '))
        {
            values.push_back(std::stol(temp));
        }
        levels.push_back(values);
        for(bool allZero = false; !allZero;)
        {
            allZero = true;
            std::vector<long> nextStage;
            std::vector<long> previousStage = levels.back();
            for(int i=1; i<previousStage.size(); i++)
            {
                long change = previousStage[i] - previousStage[i-1];
                nextStage.push_back(change);
                if(change != 0)
                {
                    allZero = false;
                }   
            }
            levels.push_back(nextStage);
        }
        for(int i=levels.size()-1; i>0; i--)
        {
            levels[i-1].insert(levels[i-1].begin(), levels[i-1].front() - levels[i].front());
        }
        sum += levels[0][0];
    }
    //std::cout << "The sum is: " << sum << std::endl;
}