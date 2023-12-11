#include "../inc/day10.hpp"
#include "../inc/macros.hpp"

#include <algorithm>
#include <map>

using namespace DayTen;

void DayTen::part1()
{
    std::string line;
    OPEN("data/day10.txt");
    std::vector<std::string> lines;
    int start[2];
    bool found = false;
    lines.push_back("");
    for(int i=1; getline(file, line); i++)
    {
        lines.push_back('.' + line + '.');
        if(!found)
        {
            int index = line.find('S');
            if(index != line.npos)
            {
                start[0] = i;
                start[1] = index+1;
                found = true;
            }
        }
    }
    lines[0] = std::string(lines[1].size(), '.');
    lines.push_back(lines.front());
    int ways = 2;
    pipe current = std::get<0>(getSecond(start[0], start[1], lines));
    for(ways; current.type!='S'; ways++)
    {
        current = getPipe(current.next[0], current.next[1], current.origin, lines);
    }
    std::cout << "The furthest distance is: " << ways/2 << std::endl;
}

void DayTen::part2()
{
    std::string line;
    OPEN("test.txt");
    std::vector<std::string> lines;
    int start[2];
    bool found = false;
    lines.push_back("");
    for(int i=1; getline(file, line); i++)
    {
        lines.push_back('O' + line + 'O');
        if(!found)
        {
            int index = line.find('S');
            if(index != line.npos)
            {
                start[0] = i;
                start[1] = index+1;
                found = true;
            }
        }
    }
    lines[0] = std::string(lines[1].size(), 'O');
    lines.push_back(lines.front());
    std::map<std::string, char> pipes;
    pipes[std::to_string(start[0]) + ',' + std::to_string(start[1])] = 'S';
    std::tuple<pipe, std::string> second = getSecond(start[0], start[1], lines);
    pipe current = std::get<0>(second);
    pipes[std::get<1>(second)] = current.type;
    char direction = current.origin;
    for(; current.type!='S';)
    {
        current = getPipe(current.next[0], current.next[1], current.origin, lines);
        pipes[std::to_string(current.next[0]) + ',' + std::to_string(current.next[1])] = current.type;
    }
    bool noChanged = false;
    while(!noChanged)
    {
        noChanged = true;
        int maxL = lines[0].size()-1;
        int maxF = lines.size()-1;
        for(int i=1; i<maxF; i++)
        {
            std::string line = lines[i];
            bool frontOpen = true;
            bool backOpen = true;
            for(int x=1; x<maxL; x++)
            {
                if(line[x] == 'O')
                {
                    frontOpen = true;
                }
                else{
                    if(frontOpen)
                    {
                        if(pipes.find(std::to_string(i) + ',' + std::to_string(x)) == pipes.end())
                        {
                            line[x] = 'O';
                            noChanged = false;
                        }
                        else
                        {
                            frontOpen = false;
                        }
                    }
                }
                if(line[maxL-x] == 'O')
                {
                    backOpen = true;
                }
                else{
                    if(backOpen)
                    {
                        if(pipes.find(std::to_string(i) + ',' + std::to_string(maxL-x)) == pipes.end())
                        {
                            line[maxL-x] = 'O';
                            noChanged = false;
                        }
                        else
                        {
                            backOpen = false;
                        }
                    }
                }
            }
        }
        for(int x=1; x<maxL; x++)
        {
            bool frontOpen = true;
            bool backOpen = true;
            for(int i=1; i<maxF; i++)
            {
                if(lines[i][x] == 'O')
                {
                    frontOpen = true;
                }
                else{
                    if(frontOpen)
                    {
                        if(pipes.find(std::to_string(i) + ',' + std::to_string(x)) == pipes.end())
                        {
                            lines[i][x] = 'O';
                            noChanged = false;
                        }
                        else
                        {
                            frontOpen = false;
                        }
                    }
                }
                if(lines[maxF-i][x] == 'O')
                {
                    backOpen = true;
                }
                else{
                    if(backOpen)
                    {
                        if(pipes.find(std::to_string(maxF-i) + ',' + std::to_string(x)) == pipes.end())
                        {
                            lines[maxF-i][x] = 'O';
                            noChanged = false;
                        }
                        else
                        {
                            backOpen = false;
                        }
                    }
                }
            }
        }
    }
    int sum = 0;
    for(int i=1; i<lines.size()-1; i++)
    {
        std::string line = lines[i];
        for(int x=1; x<line.size()-1; x++)
        {
            if(line[x] != 'O')
            {
                sum++;
            }
        }
    }
    sum -= pipes.size();
    std::cout << "The sum is: " << sum << std::endl;
}


pipe DayTen::getPipe(int y, int x, char origin, std::vector<std::string> lines)
{
    pipe temp;
    switch (lines[y][x])
    {
        case '|':
            if(origin == 'n')
            {
                temp.next[0] = y+1;
                temp.next[1] = x;
                temp.origin = 'n';
            }
            else
            {
                temp.next[0] = y-1;
                temp.next[1] = x;
                temp.origin = 's';
            }
            break;
        case '-':
            if(origin == 'w')
            {
                temp.next[0] = y;
                temp.next[1] = x+1;
                temp.origin = 'w';
            }
            else
            {
                temp.next[0] = y;
                temp.next[1] = x-1;
                temp.origin = 'e';
            }
            break;
        case 'L':
            if(origin == 'n')
            {
                temp.next[0] = y;
                temp.next[1] = x+1;
                temp.origin = 'w';
            }
            else
            {
                temp.next[0] = y-1;
                temp.next[1] = x;
                temp.origin = 's';
            }
            break;
        case '7':
            if(origin == 's')
            {
                temp.next[0] = y;
                temp.next[1] = x-1;
                temp.origin = 'e';
            }
            else
            {
                temp.next[0] = y+1;
                temp.next[1] = x;
                temp.origin = 'n';
            }
            break;
        case 'J':
            if(origin == 'n')
            {
                temp.next[0] = y;
                temp.next[1] = x-1;
                temp.origin = 'e';
            }
            else
            {
                temp.next[0] = y-1;
                temp.next[1] = x;
                temp.origin = 's';
            }
            break;
        case 'F':
            if(origin == 's')
            {
                temp.next[0] = y;
                temp.next[1] = x+1;
                temp.origin = 'w';
            }
            else
            {
                temp.next[0] = y+1;
                temp.next[1] = x;
                temp.origin = 'n';
            }
            break;
    }
    temp.type = lines[temp.next[0]][temp.next[1]];
    return temp;
}

std::tuple<pipe, std::string> DayTen::getSecond(int y, int x, std::vector<std::string> lines)
{
    char next = lines[y-1][x];
    std::tuple<pipe, std::string> value;
    if(next == '|' || next == '7' || next == 'F')
    {
        return {getPipe(y-1, x, 's', lines), std::to_string(y-1) + ',' + std::to_string(x)};
    }
    next = lines[y+1][x];
    if(next == '|' || next == 'L' || next == 'J')
    {
        return {getPipe(y+1, x, 'n', lines), std::to_string(y+1) + ',' + std::to_string(x)};
    }
    next = lines[y][x-1];
    if(next == '-' || next == 'L' || next == 'F')
    {
        return {getPipe(y, x-1, 'e', lines), std::to_string(y) + ',' + std::to_string(x-1)};
    }
    return {getPipe(y, x+1, 'w', lines), std::to_string(y) + ',' + std::to_string(x+1)};   
}