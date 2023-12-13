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
    pipe current = getFirst(start[0], start[1], lines);
    for(ways; current.type!='S'; ways++)
    {
        current = getPipe(current.next[0], current.next[1], current.origin, lines);
    }
    std::cout << "The furthest distance is: " << ways/2 << std::endl;
}

void DayTen::part2()
{
    std::string line;
    OPEN("data/day10.txt");
    std::vector<std::string> lines;
    int start[2];
    bool found = false;
    lines.push_back("");
    for(int i=1; getline(file, line); i++)
    {
        lines.push_back('O' + line + 'O');
        if(!found)
        {
            int index = lines.back().find('S');
            if(index != line.npos)
            {
                start[0] = i;
                start[1] = index;
                found = true;
            }
        }
    }
    lines[0] = std::string(lines[1].size(), 'O');
    lines.push_back(lines.front());
    std::map<std::string, char> pipes;
    pipe current = getFirst(start[0], start[1], lines);
    while(current.type != 'S')
    {
        pipes[std::to_string(current.next[0]) + ',' + std::to_string(current.next[1])] = current.type;
        current = getPipe(current.next[0], current.next[1], current.origin, lines);
    }
    bool noChanged = false;
    int maxL = lines[0].size()-1;
    int maxF = lines.size()-1;
    while(!noChanged)
    {
        noChanged = true;
        for(int i=1; i<maxF; i++)
        {
            std::string line = lines[i];
            bool frontDownOpen = true;
            bool frontUpOpen = true;
            bool backDownOpen = true;
            bool backUpOpen = true;
            for(int x=1; x<maxL; x++)
            {
                if(line[x] == 'O')
                {
                    frontDownOpen = true;
                    frontUpOpen = true;
                }
                else{
                    if(frontUpOpen || frontDownOpen)
                    {
                        if(pipes.find(std::to_string(i) + ',' + std::to_string(x)) == pipes.end())
                        {
                            lines[i][x] = 'O';
                            noChanged = false;
                        }
                        else
                        {
                            char letter = line[x];
                            if(letter == '|' || letter == 'L' || letter == 'J')
                            {
                                frontUpOpen = false;
                            }
                            if(letter == '|' || letter == 'F' || letter == '7')
                            {
                                frontDownOpen = false;
                            }
                        }
                    }
                }
                if(line[maxL-x] == 'O')
                {
                    backUpOpen = true;
                    backDownOpen = true;
                }
                else{
                    if(backDownOpen || backUpOpen)
                    {
                        if(pipes.find(std::to_string(i) + ',' + std::to_string(maxL-x)) == pipes.end())
                        {
                            lines[i][maxL-x] = 'O';
                            noChanged = false;
                        }
                        else
                        {
                            char letter = line[maxL-x];
                            if(letter == '|' || letter == 'L' || letter == 'J')
                            {
                                backUpOpen = false;
                            }
                            if(letter == '|' || letter == 'F' || letter == '7')
                            {
                                backDownOpen = false;
                            }
                        }
                    }
                }
            }
        }
        for(int x=1; x<maxL; x++)
        {
            bool frontLOpen = true;
            bool frontROpen = true;
            bool backLOpen = true;
            bool backROpen = true;
            for(int i=1; i<maxF; i++)
            {
                if(lines[i][x] == 'O')
                {
                    frontLOpen = true;
                    frontROpen = true;
                }
                else{
                    if(frontLOpen || frontROpen)
                    {
                        if(pipes.find(std::to_string(i) + ',' + std::to_string(x)) == pipes.end())
                        {
                            lines[i][x] = 'O';
                            noChanged = false;
                        }
                        else
                        {
                            char letter = lines[i][x];
                            if(letter == '-' || letter == '7' || letter == 'J')
                            {
                                frontLOpen = false;
                            }
                            if(letter == '-' || letter == 'F' || letter == 'L')
                            {
                                frontROpen = false;
                            }
                        }
                    }
                }
                if(lines[maxF-i][x] == 'O')
                {
                    backLOpen = true;
                    backROpen = true;
                }
                else{
                    if(backLOpen || backROpen)
                    {
                        if(pipes.find(std::to_string(maxF-i) + ',' + std::to_string(x)) == pipes.end())
                        {
                            lines[maxF-i][x] = 'O';
                            noChanged = false;
                        }
                        else
                        {
                            char letter = lines[maxF-i][x];
                            if(letter == '-' || letter == '7' || letter == 'J')
                            {
                                backLOpen = false;
                            }
                            if(letter == '-' || letter == 'F' || letter == 'L')
                            {
                                backROpen = false;
                            }
                        }
                    }
                }
            }
        }
    }
    unsigned int sum = 0;
    for(int i=1; i<maxF; i++)
    {
        std::string line = lines[i];
        for(int x=1; x<maxL; x++)
        {
            if(line[x] != 'O')
            {
                sum++;
            }
        }
    }
    sum -= pipes.size();
    std::cout << pipes.size() << std::endl;
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
    temp.type = lines[y][x];
    return temp;
}

pipe DayTen::getFirst(int y, int x, std::vector<std::string> lines)
{
    pipe temp;
    char next = lines[y-1][x];
    if(next == '|' || next == '7' || next == 'F')
    {
        temp.next[0] = y-1;
        temp.next[1] = x;
        temp.origin = 's';
        temp.type = '|';
    }
    else
    {
        next = lines[y+1][x];
        if(next == '|' || next == 'L' || next == 'J')
        {
            temp.next[0] = y+1;
            temp.next[1] = x;
            temp.origin = 'n';
            temp.type = '|';
        }
        else
        {
            next = lines[y][x-1];
            if(next == '-' || next == 'L' || next == 'F')
            {
                temp.next[0] = y;
                temp.next[1] = x-1;
                temp.origin = 'e';
                temp.type = '-';
            }
            else
            {
                temp.next[0] = y;
                temp.next[1] = x+1;
                temp.origin = 'w';
                temp.type = '-';
            }
        }
    }
    return temp;
}