#include "../inc/day5.hpp"
#include "../inc/macros.hpp"

#include <vector>
#include <sstream>
#include <cstdlib>

using namespace DayFive;

void DayFive::part1()
{
    std::vector<std::vector<mapPart>> maps;
    std::vector<unsigned long long> seeds;
    std::string line;
    OPEN("data/day5.txt")
    getline(file, line);
    line = line.erase(0, line.find(':')+2);
    std::stringstream ss (line);
    std::string temp;
    while(getline(ss, temp, ' '))
    {
        seeds.push_back(std::strtoul(temp.c_str(), NULL, 10));

    }
    while(getline(file, line))
    {
        if(line.empty())
        {
            std::vector<mapPart> map;
            maps.push_back(map);
            getline(file,line);
            continue;
        }
        maps.back().push_back(getValues(line));
    }
    for(int seed=0; seed<seeds.size(); seed++)
    {
        for(int map = 0; map<maps.size(); map++)
        {
            std::vector<mapPart> chart = maps[map];
            for(int match = 0; match < chart.size(); match++)
            {
                if(seeds[seed] >= chart[match].start && seeds[seed] <= chart[match].end)
                {
                    seeds[seed] += chart[match].change;
                    break;
                }
            }
        }
    }
    unsigned long long min = seeds[0];
    for(int x = 1; x<seeds.size();x++)
    {
        if(seeds[x] < min)
        {
            min = seeds[x];
        }
    }
    std::cout << "The smallest number is: " << min << std::endl;
}

mapPart DayFive::getValues(std::string line)
{
    mapPart part;
    unsigned long long values[3]; 
    std::stringstream ss(line);
    std::string temp;
    for(int i=0; getline(ss, temp, ' '); i++)
    {
        values[i] = std::strtoul(temp.c_str(), NULL, 10);
    }
    part.start = values[1];
    part.end = values[1] + values[2] - 1;
    part.change = values[0] - values[1];
    return part;
}

void DayFive::part2()
{
    std::vector<std::vector<mapPart>> maps;
    std::vector<startingSeeds> seeds;
    std::string line;
    OPEN("data/day5.txt")
    getline(file, line);
    line = line.erase(0, line.find(':')+2);
    std::stringstream ss (line);
    std::string temp;
    while(getline(ss, temp, ' '))
    {
        startingSeeds seed;
        seed.start = std::strtoul(temp.c_str(), NULL, 10);
        getline(ss, temp, ' ');
        seed.end = std::strtoul(temp.c_str(), NULL, 10) + seed.start - 1;
        seeds.push_back(seed);
    }
    while(getline(file, line))
    {
        if(line.empty())
        {
            std::vector<mapPart> map;
            maps.push_back(map);
            getline(file,line);
            continue;
        }
        mapPart part;
        unsigned long long values[3]; 
        std::stringstream ss(line);
        std::string temp;
        for(int i=0; getline(ss, temp, ' '); i++)
        {
            values[i] = std::strtoul(temp.c_str(), NULL, 10);
        }
        part.start = values[0];
        part.end = values[0] + values[2];
        part.change = values[1] - values[0];
        maps.back().push_back(part);
    }
    for(unsigned long long i=0;true;i++)
    {
        unsigned long long number = i;
        for(int map = maps.size()-1; map>=0; map--)
        {
            std::vector<mapPart> chart = maps[map];
            for(int match = 0; match < chart.size(); match++)
            {
                if(number >= chart[match].start && number < chart[match].end)
                {
                    number += chart[match].change;
                    break;
                }
            }
        }
        for(int x=0; x<seeds.size(); x++)
        {
            if(number>= seeds[x].start && number<=seeds[x].end)
            {
                std::cout << "The smallest location is: " << i << std::endl;
                return; 
            }
        }
    }
}