#include "../inc/day12.hpp"
#include "../inc/macros.hpp"

#include <string>
#include <vector>

using namespace DayTwelve;

void DayTwelve::part1()
{
    std::string line;
    std::vector<int> orders;
    std::string order;
    std::string springs;
    int sum = 0;
    OPEN("test.txt")
    {
        std::stringstream ss (line);
        getline(ss, springs, ' ');
        while(getline(ss, order, ','))
        {
            orders.push_back(std::stoi(order));
        }

    }
}

bool DayTwelve::checkSprings(std::vector<int> orders, std::string springs)
{
    int index = 0;
    int count = 0;
    bool onWorking = false;
    for(int i=0; i<springs.size(); i++)
    {
        if(springs[i] == '#')
        {
            onWorking = true;
            count++;
            if(count > orders[index])
            {
                return false;
            }
        }
        else if(onWorking)
        {
            if(count != orders[index])
            {
                return false;
            }
            count = 0;
            index++;
            if(index >= orders.size())
            {
                return false;
            }
            onWorking = false;
        }
    }
    return true;
}