#include "../inc/day13.hpp"
#include "../inc/macros.hpp"

#include <vector>
#include <string>

using namespace DayThirteen;

void DayThirteen::part1()
{
    int sum = 0;
    std::string line;
    OPEN("data/day13.txt");
    std::vector<std::string> horizontal;
    while(getline(file, line))
    {
        std::vector<std::string> verticals;
        horizontal = {line};
        for(int i=0; i<line.size(); i++)
        {
            verticals.push_back(line.substr(i, 1));
        }
        while(getline(file, line))
        {
            if(line.empty())
            {
                break;
            }
            horizontal.push_back(line);
            for(int i=0; i<line.size(); i++)
            {
                verticals[i] += line[i];
            }
        }
        bool found = false;
        int index = 0;
        for(int i=0; i<verticals.size()-1 && !found; i++)
        {
            if(verticals[i] == verticals[i+1])
            {
                found = true;
                index = i+1;
                for(int x=1; x<i+1 && x+i+1<verticals.size(); x++)
                {
                    if(verticals[i-x] != verticals[i+1+x])
                    {
                        found = false;
                        break;
                    }
                }
            }
        }
        for(int i=0; i<horizontal.size()-1 && !found; i++)
        {
            if(horizontal[i] == horizontal[i+1])
            {
                found = true;
                index = (i+1)*100;
                for(int x=1; x<i+1; x++)
                {
                    if(horizontal[i-x] != horizontal[i+1+x])
                    {
                        found = false;
                        break;
                    }
                }
            }
        }
        sum += index;
    }
    //std::cout << "The sum is: " << sum << std::endl;
}

void DayThirteen::part2()
{
    long sum = 0;
    std::string line;
    OPEN("data/day13.txt");
    std::vector<std::string> horizontal;
    while(getline(file, line))
    {
        std::vector<std::string> verticals;
        horizontal = {line};
        for(int i=0; i<line.size(); i++)
        {
            verticals.push_back(line.substr(i, 1));
        }
        while(getline(file, line))
        {
            if(line.empty())
            {
                break;
            }
            horizontal.push_back(line);
            for(int i=0; i<line.size(); i++)
            {
                verticals[i] += line[i];
            }
        }
        bool found = false;
        int differences = 0;
        int index = 0;
        for(int i=0; i<verticals.size()-1 && !found; i++)
        {
            differences = 0;
            int diff = getDifference(verticals[i], verticals[i+1]);
            if(diff < 2)
            {
                differences += diff;
                found = true;
                index = i+1;
                for(int x=1; x<i+1 && x+i+1<verticals.size(); x++)
                {
                    diff = getDifference(verticals[i-x], verticals[i+x+1]);
                    if(diff + differences > 1)
                    {
                        found = false;
                        break;
                    }
                    differences += diff;
                }
                if(differences != 1)
                {
                    found = false;
                }
            }
        }
        for(int i=0; i<horizontal.size()-1 && !found; i++)
        {
            differences = 0;
            int diff = getDifference(horizontal[i], horizontal[i+1]);
            if(diff < 2)
            {
                differences += diff;
                found = true;
                index = (i+1)*100;
                for(int x=1; x<i+1 && x+i+1<horizontal.size(); x++)
                {
                    diff = getDifference(horizontal[i-x], horizontal[i+x+1]);
                    if(differences + diff > 1)
                    {
                        found = false;
                        break;
                    }
                    differences += diff;
                }
                if(differences != 1)
                {
                    found = false;
                }
            }
        }
        sum += index;
    }
    //std::cout << "The sum is: " << sum << std::endl;
}

int DayThirteen::getDifference(std::string first, std::string second)
{
    int sum = 0;
    for(int i=0; i!=first.size(); i++)
    {
        if(first[i] != second[i])
        {
            sum++;
        }
    }
    return sum;
}