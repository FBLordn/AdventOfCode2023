#include "../inc/day11.hpp"
#include "../inc/macros.hpp"

#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace DayEleven;

void DayEleven::part1()
{
    std::string line;
    int sum = 0;
    OPEN("data/day11.txt");
    std::vector<int> xGalax;
    std::vector<int> yGalax;
    std::vector<std::string> data;
    while(getline(file, line))
    {
        data.push_back(line);
        if(line.find('#') == line.npos)
        {
            data.push_back(std::string(line.size(), '.'));
        }
    }
    for(int i=0; i<data[0].size(); i++)
    {
        bool lineClear = true;
        for(int x=0; x<data.size(); x++)
        {
            if(data[x][i] == '#')
            {
                lineClear = false;
                break;
            }
        }
        if(lineClear)
        {
            for(int x=0; x<data.size(); x++)
            {
                data[x].insert(i, ".");
            }
            i++;
        }
    }
    for(int i=0; i<data.size(); i++)
    {
        std::string line = data[i];
        for(int x=0; x<line.size(); x++)
        {
            if(line[x] != '.')
            {
                xGalax.push_back(x);
                yGalax.push_back(i);
            }
        }
    }

    for(int i=0; i<xGalax.size()-1; i++)
    {
        for(int x=i+1; x<xGalax.size(); x++)
        {
            sum += std::abs(xGalax[i] - xGalax[x]) + std::abs(yGalax[i] - yGalax[x]);
        }
    }
    //std::cout << "The sum is: " << sum << std::endl;
}


void DayEleven::part2()
{
    std::string line;
    unsigned long sum = 0;
    OPEN("data/day11.txt");
    std::vector<int> xGalax;
    std::vector<int> yGalax;
    std::vector<std::string> data;
    std::vector<int> xDistances;
    while(getline(file, line))
    {
        data.push_back(line);
        if(line.find('#') == line.npos)
        {
            xDistances.push_back(1000000);
        }
        else
        {
            xDistances.push_back(1);
        }
    }
    std::vector<int> yDistances;
    yDistances.reserve(data.size());
    for(int i=0; i<data[0].size(); i++)
    {
        bool lineClear = true;
        for(int x=0; x<data.size(); x++)
        {
            if(data[x][i] == '#')
            {
                lineClear = false;
                break;
            }
        }
        if(lineClear)
        {
            yDistances.push_back(1000000);
        }
        else
        {
            yDistances.push_back(1);
        }
    }
    for(int i=0; i<data.size(); i++)
    {
        std::string line = data[i];
        for(int x=0; x<line.size(); x++)
        {
            if(line[x] != '.')
            {
                xGalax.push_back(x);
                yGalax.push_back(i);
            }
        }
    }

    for(int i=0; i<xGalax.size()-1; i++)
    {
        for(int x=i+1; x<xGalax.size(); x++)
        {
            for(int l=std::min(xGalax[i], xGalax[x]); l<std::max(xGalax[i], xGalax[x]); l++)
            {
                sum += yDistances[l];
            }
            for(int l=std::min(yGalax[i], yGalax[x]); l<std::max(yGalax[i], yGalax[x]); l++)
            {
                sum += xDistances[l];
            }
        }
    }
    //std::cout << "The sum is: " << sum << std::endl;
}