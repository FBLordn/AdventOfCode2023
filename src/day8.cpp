#include "../inc/day8.hpp"
#include "../inc/macros.hpp"

#include <numeric>
#include <map>

using namespace DayEight;

void DayEight::part1()
{
    std::string line;
    std::map<std::string, node> paths;
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
        paths.insert({temp.name, temp});
    }
    node current = paths["AAA"];
    int step = 0;
    int max = instructions.size();
    for(step; current.name != "ZZZ"; step++)
    {
        if(instructions[step%max] == 'L')
        {
            current = paths[current.left];
        }
        else
        {
            current = paths[current.right];
        }
    }
    std::cout << "The amount is: " << step << std::endl;
}

void DayEight::part2()
{
    std::string line;
    std::map<std::string, node> paths;
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
        paths.insert({temp.name, temp});
    }
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
                current = paths[current.left];
            }
            else
            {
                current = paths[current.right];
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