#include "../inc/day6.hpp"
#include "../inc/macros.hpp"

#include <algorithm>

using namespace DaySix;

void DaySix::part1()
{
    int sum = 1;
    OPEN("data/day6.txt");
    std::string line;
    getline(file, line);
    std::vector<int> times = getNumber(line);
    getline(file, line);
    std::vector<int> records = getNumber(line);
    for(int race=0; race<times.size(); race++)
    {
        int i = 1;
        for(i; (times[race]-i)*i <= records[race]; i++)
        {
            continue;
        }
        sum *= (times[race] - 2*i + 1);
    }
    std::cout<<"The sum is: " << sum << std::endl;
}

std::vector<int> DaySix::getNumber(std::string line){
    std::vector<int> temp;
    for(int i=0; i<line.size(); i++)
    {
        if(isdigit(line[i]))
        {
            int endN = line.find(' ', i);
            if(endN == line.npos)
            {
                endN = line.size();
            }
            temp.push_back(std::stoi(line.substr(i, endN-1)));
            i = endN + 1;
        }
    }
    return temp;
}


void DaySix::part2()
{
    OPEN("data/day6.txt");
    std::string line;
    std::vector<unsigned long long> values;
    while(getline(file, line))
    {
        line.erase(0, line.find(':')+1);
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        values.push_back(std::stoull(line));
    }
    unsigned long i = 1;
    for(i; (values[0]-i)*i <= values[1]; i++)
    {
        continue;
    }
    std::cout << "The sum is: " << values[0] - 2*i + 1 << std::endl;
}