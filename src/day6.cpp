#include "../inc/day6.hpp"
#include "../inc/macros.hpp"

#include <algorithm>
#include <math.h>
#include <cstdlib>

using namespace DaySix;

void DaySix::part1()
{
    int sum = 1;
    OPEN("test.txt");
    std::string line;
    getline(file, line);
    std::vector<int> times = getNumber(line);
    getline(file, line);
    std::vector<int> records = getNumber(line);
    for(int race=0; race<times.size(); race++)
    {
        sum *= (times[race] - 2 * (std::floor((times[race]/2.0) - std::sqrt(std::pow(times[race]/2.0, 2) - records[race]))) - 1);
    }
    //std::cout<<"The sum is: " << sum << std::endl;
}

std::vector<int> DaySix::getNumber(std::string line){
    std::vector<int> temp;
    int number = 0;
    for(int i=0; i<line.size(); i++)
    {
        if(isdigit(line[i]))
        {
            number = number*10 + (int)line[i]-48;
            continue;
        }
        if(number != 0)
        {
            temp.push_back(number);
        }
        number = 0;
    }
    temp.push_back(number);
    return temp;
}


void DaySix::part2()
{
    OPEN("data/day6.txt");
    std::string line;
    std::vector<unsigned long long> values;
    while(getline(file, line))
    {
        std::string temp;
        for(int i=0; i<line.size();i++)
        {
            if(isdigit(line[i]))
            {
                temp += line[i];
            }
        }
        values.push_back(std::stoull(temp));
    }
    long sum = (values[0] - 2 * (std::floor((values[0]/2.0) - std::sqrt(std::pow(values[0]/2.0, 2) - values[1]))) - 1);
    //std::cout << "The sum is: " << sum << std::endl;
}