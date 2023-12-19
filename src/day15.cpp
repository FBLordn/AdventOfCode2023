#include "../inc/day15.hpp"
#include "../inc/macros.hpp"

#include <string>
#include <vector>
#include <algorithm>

using namespace DayFifteen;

void DayFifteen::part1()
{
    int sum = 0;
    std::string line;
    OPEN("data/day15.txt");
    while(getline(file, line, ','))
    {
        int result = 0;
        for(int i=0; i<line.size(); i++)
        {
            result = ((result + (int)line[i]) * 17) % 256;
        }
        sum += result;
    }
    std::cout << "The sum is: " << sum << std::endl;
}

void DayFifteen::part2()
{
    int sum = 0;
    std::vector<std::vector<std::string>> boxes(256);
    std::string line;
    OPEN("data/day15.txt");
    while(getline(file, line, ','))
    {
        int result = 0;
        for(int i=0; i<line.size(); i++)
        {
            char c = line[i];
            if(c == '=')
            {
                std::string label = line.substr(0, i);
                std::vector<std::string> box = boxes[result];
                int number = (int)line[i+1] - 48;
                bool found = false;
                for(int index = 0; index < box.size(); index++)
                {
                    if(box[index].find(label) != box[index].npos)
                    {
                        boxes[result][index] = label + " " + std::to_string(number);
                        found = true;
                        break;
                    }
                }
                if(!found)
                {
                    boxes[result].push_back(label + " " + std::to_string(number));
                }
                break;
            }
            else if(c == '-')
            {
                std::string label = line.substr(0, i);
                std::vector<std::string> box = boxes[result];
                for(int index = 0; index < box.size(); index++)
                {
                    if(box[index].find(label) != box[index].npos)
                    {
                        boxes[result].erase(boxes[result].begin()+index);
                        break;
                    }
                }
                break;
            }
            else
            {
                result = ((result + (int)c) * 17) % 256;
            }
        }
    }
    for(int i = 0; i < boxes.size(); i++)
    {
        std::vector<std::string> box = boxes[i];
        for(int x = 0; x < box.size(); x++)
        {
            sum += ((int)box[x].back() - 48) * (i+1) * (x+1);
        }
    }
    std::cout << "The sum is: " << sum << std::endl;
}