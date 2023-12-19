#include "../inc/day14.hpp"
#include "../inc/macros.hpp"

#include <string>
#include <vector>

using namespace DayFourteen;

void DayFourteen::part1()
{
    std::string line;
    int sum = 0;
    std::vector<std::string> input;
    OPEN("data/day14.txt");
    while(getline(file, line))
    {
        input.push_back(line);
    }
    for(int x=0; x<input[0].size(); x++)
    {
        int empty = 0;
        for(int y=0; y<input.size(); y++)
        {
            if(input[y][x] == '#')
            {
                empty = y+1;
            }
            else if(input[y][x] == 'O')
            {
                sum += input.size() - empty;
                empty++;
            }
        }
    }
    std::cout << "The sum is: " << sum << std::endl;
}

void DayFourteen::part2()
{

    std::string line;
    int sum = 0;
    std::vector<std::string> input;
    OPEN("data/day14.txt");
    while(getline(file, line))
    {
        input.push_back(line);
    }
    int lineSize = input[0].size();
    int fileSize = input.size();
    bool shortend = false;
    for(int x=0; x<lineSize; x++)
    {
        int empty = 0;
        for(int y=0; y<fileSize; y++)
        {
            if(input[y][x] == '#')
            {
                empty = y+1;
            }
            else if(input[y][x] == 'O')
            {
                input[y][x] = '.';
                input[empty][x] = 'O';
                empty++;
            }
        }
    }
    for(int y=0; y<fileSize; y++)
    {
        int empty = lineSize-1;
        for(int x=lineSize-1; x>=0; x--)
        {
            if(input[y][x] == '#')
            {
                empty = x-1;
            }
            else if(input[y][x] == 'O')
            {
                input[y][x] = '.';
                input[y][empty] = 'O';
                empty--;
            }
        }
    }
    for(int x=0; x<lineSize; x++)
    {
        int empty = fileSize-1;
        for(int y=fileSize-1; y>=0; y--)
        {
            if(input[y][x] == '#')
            {
                empty = y-1;
            }
            else if(input[y][x] == 'O')
            {
                input[y][x] = '.';
                input[empty][x] = 'O';
                empty--;
            }
        }
    }
    for(int y=0; y<fileSize; y++)
    {
        int empty = 0;
        for(int x=0; x<lineSize; x++)
        {
            if(input[y][x] == '#')
            {
                empty = x+1;
            }
            else if(input[y][x] == 'O')
            {
                input[y][x] = '.';
                input[y][empty] = 'O';
                empty++;
            }
        }
    }
    std::vector<std::string> first = input;
    for(int circle = 999999999; circle > 0; circle--)
    {
        for(int x=0; x<lineSize; x++)
        {
            int empty = 0;
            for(int y=0; y<fileSize; y++)
            {
                if(input[y][x] == '#')
                {
                    empty = y+1;
                }
                else if(input[y][x] == 'O')
                {
                    input[y][x] = '.';
                    input[empty][x] = 'O';
                    empty++;
                }
            }
        }
        for(int y=0; y<fileSize; y++)
        {
            int empty = lineSize-1;
            for(int x=lineSize-1; x>=0; x--)
            {
                if(input[y][x] == '#')
                {
                    empty = x-1;
                }
                else if(input[y][x] == 'O')
                {
                    input[y][x] = '.';
                    input[y][empty] = 'O';
                    empty--;
                }
            }
        }
        for(int x=0; x<lineSize; x++)
        {
            int empty = fileSize-1;
            for(int y=fileSize-1; y>=0; y--)
            {
                if(input[y][x] == '#')
                {
                    empty = y-1;
                }
                else if(input[y][x] == 'O')
                {
                    input[y][x] = '.';
                    input[empty][x] = 'O';
                    empty--;
                }
            }
        }
        for(int y=0; y<fileSize; y++)
        {
            int empty = 0;
            for(int x=0; x<lineSize; x++)
            {
                if(input[y][x] == '#')
                {
                    empty = x+1;
                }
                else if(input[y][x] == 'O')
                {
                    input[y][x] = '.';
                    input[y][empty] = 'O';
                    empty++;
                }
            }
        }
        if(!shortend)
        {
            if(input == first)
            {
                circle = circle % (1000000000-circle);
                shortend = true;
            }
        }
        if(circle % 1000000 == 0)
        {
            std::cout << circle << std::endl;
        }
    }
    for(int y=0; y<fileSize; y++)
    {
        for(int x=0; x<lineSize; x++)
        {
            if(input[y][x] == 'O')
            {
                sum += fileSize - y;
            }
        }
    }
    std::cout << "The sum is: " << sum << std::endl;
}