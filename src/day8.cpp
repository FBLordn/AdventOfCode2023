#include "../inc/day8.hpp"
#include "../inc/macros.hpp"

#include <algorithm>
#include <numeric>

using namespace DayEight;

void DayEight::part1()
{
    std::string line = "temp";
    std::vector<node> paths;
    OPEN("data/day8.txt")
    std::string instructions;
    getline(file, instructions);
    getline(file, line); //Skip empty line
    while(getline(file, line))
    {
        node temp;
        temp.name = line.substr(0,3);
        temp.left = line.substr(7,3);
        temp.right = line.substr(12, 3);
        paths.push_back(temp);
    }
    std::sort(paths.begin(), paths.end(), compareNames);
    node current = paths[0];
    int max = instructions.size();
    int step = 0;
    for(step; current.name != "ZZZ"; step++)
    {
        if(instructions[step%max] == 'L')
        {
            current = getNode(paths, current.left);
        }
        else
        {
            current = getNode(paths, current.right);
        }
    }
    std::cout << "The amount is: " << step << std::endl;
}

node DayEight::getNode(std::vector<node> paths, std::string name){
    int low = 0;
    int high = paths.size();
    node current = paths[(high-low)/2];
    for(;current.name != name; current = paths[low+(high-low)/2])
    {
        if (current.name < name)
        {
            low += (high-low)/2 + 1;
        }
        else
        {
            high -= (high-low)/2 + 1;
        }
    }
    return current;
}

bool DayEight::compareNames(const node& a, const node& b)
{
    return a.name < b.name;
}

void DayEight::part2()
{
    std::string line;
    std::vector<node> paths;
    std::vector<node> starts;
    OPEN("data/day8.txt")
    std::string instructions;
    getline(file, instructions);
    getline(file, line);
    while(getline(file, line))
    {
        node temp;
        temp.name = line.substr(0,3);
        temp.left = line.substr(7,3);
        temp.right = line.substr(12, 3);
        if(temp.name[2] == 'A')
        {
            starts.push_back(temp);
        }
        paths.push_back(temp);
    }
    std::sort(paths.begin(), paths.end(), compareNames);
    int max = instructions.size();
    unsigned long long number = 1;
    for(int i=0; i<starts.size(); i++)
    {
        node current = starts[i];
        unsigned long x = 0;
        for(x;; x++)
        {
            if(instructions[x%max] == 'L')
            {
                current = getNode(paths, current.left);
            }
            else
            {
                current = getNode(paths, current.right);
            }
            if(current.name[2] == 'Z')
            {
                break;
            }
        }
        number = std::lcm(number, x+1);
    }
    std::cout << "The amount is: " << number << std::endl;
}