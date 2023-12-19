#include "../inc/day16.hpp"
#include "../inc/macros.hpp"

#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace DaySixteen;

void DaySixteen::part1()
{
    std::queue<beam> beams;
    std::map<std::string, std::string> filled;
    beam next;
    next.dir = 'e';
    next.x = 0;
    next.y = 0;
    beams.push(next);
    std::string line;
    std::vector<std::string> input;
    OPEN("data/day16.txt")
    while(getline(file, line))
    {
        input.push_back(line);
    }
    for(beam current = beams.front(); !beams.empty(); current = beams.front())
    {
        beams.pop();
        while(current.x < input[0].size() && current.x >= 0 && current.y >= 0 && current.y < input.size())
        {
            
            std::string name = std::to_string(current.y) + "," + std::to_string(current.x);
            if(filled[name].find(current.dir) == filled[name].npos)
            {
                filled[name] += current.dir;
            }
            else
            {
                break;
            }
            switch (input[current.y][current.x])
            {
            case '-':
                if(current.dir == 'n' || current.dir == 's')
                {
                    next.dir = 'e';
                    next.x = current.x;
                    next.y = current.y;
                    beams.push(next);    
                    current.dir = 'w';
                }
                break;
            case '/':
                if(current.dir == 'n')
                {
                    current.dir = 'e';
                }
                else if(current.dir == 's')
                {
                    current.dir = 'w';
                }
                else if(current.dir == 'w')
                {
                    current.dir = 's';
                }
                else
                {
                    current.dir = 'n';
                }
                break;
            case '\\':
                if(current.dir == 'n')
                {
                    current.dir = 'w';
                }
                else if(current.dir == 's')
                {
                    current.dir = 'e';
                }
                else if(current.dir == 'w')
                {
                    current.dir = 'n';
                }
                else
                {
                    current.dir = 's';
                }
                break;
            case '|':
                if(current.dir == 'e' || current.dir == 'w')
                {
                    next.dir = 'n';
                    next.x = current.x;
                    next.y = current.y;
                    beams.push(next);    
                    current.dir = 's';
                }
                break;
            default:
                break;
            }
            switch (current.dir)
            {
            case 'n':
                current.y--;
                break;
            
            case 's':
                current.y++;
                break;
            case 'w':
                current.x--;
                break;
            case 'e':
                current.x++;
                break;
            }
        }
    }
    //std::cout << "The sum is: " << filled.size() << std::endl;
}

void DaySixteen::part2()
{
    std::string line;
    std::vector<std::string> input;
    OPEN("data/day16.txt")
    while(getline(file, line))
    {
        input.push_back(line);
    }
    std::queue<beam> beams;
    beam next;
    int max = 0;
    for(int i=0; i<input[0].size()*2; i++)
    {
        std::map<std::string, std::string> filled;
        next.x = i/2;
        if(i%2==0)
        {
            next.dir = 'n';
            next.y = input.size()-1;
        }
        else
        {
            next.dir = 's';
            next.y = 0;    
        }
        beams.push(next);
        for(beam current = beams.front(); !beams.empty(); current = beams.front())
        {
            beams.pop();
            while(current.x < input[0].size() && current.x >= 0 && current.y >= 0 && current.y < input.size())
            {
                
                std::string name = std::to_string(current.y) + "," + std::to_string(current.x);
                if(filled[name].find(current.dir) == filled[name].npos)
                {
                    filled[name] += current.dir;
                }
                else
                {
                    break;
                }
                switch (input[current.y][current.x])
                {
                case '-':
                    if(current.dir == 'n' || current.dir == 's')
                    {
                        next.dir = 'e';
                        next.x = current.x;
                        next.y = current.y;
                        beams.push(next);    
                        current.dir = 'w';
                    }
                    break;
                case '/':
                    if(current.dir == 'n')
                    {
                        current.dir = 'e';
                    }
                    else if(current.dir == 's')
                    {
                        current.dir = 'w';
                    }
                    else if(current.dir == 'w')
                    {
                        current.dir = 's';
                    }
                    else
                    {
                        current.dir = 'n';
                    }
                    break;
                case '\\':
                    if(current.dir == 'n')
                    {
                        current.dir = 'w';
                    }
                    else if(current.dir == 's')
                    {
                        current.dir = 'e';
                    }
                    else if(current.dir == 'w')
                    {
                        current.dir = 'n';
                    }
                    else
                    {
                        current.dir = 's';
                    }
                    break;
                case '|':
                    if(current.dir == 'e' || current.dir == 'w')
                    {
                        next.dir = 'n';
                        next.x = current.x;
                        next.y = current.y;
                        beams.push(next);    
                        current.dir = 's';
                    }
                    break;
                default:
                    break;
                }
                switch (current.dir)
                {
                case 'n':
                    current.y--;
                    break;
                
                case 's':
                    current.y++;
                    break;
                case 'w':
                    current.x--;
                    break;
                case 'e':
                    current.x++;
                    break;
                }
            }
        }
        if(max < filled.size())
        {
            max = filled.size();
        }
    }
    for(int i=0; i<input.size()*2; i++)
    {
        std::map<std::string, std::string> filled;
        next.y = i/2;
        if(i%2==0)
        {
            next.dir = 'w';
            next.x = input[0].size()-1;
        }
        else
        {
            next.dir = 'e';
            next.x = 0;    
        }
        beams.push(next);
        for(beam current = beams.front(); !beams.empty(); current = beams.front())
        {
            beams.pop();
            while(current.x < input[0].size() && current.x >= 0 && current.y >= 0 && current.y < input.size())
            {
                
                std::string name = std::to_string(current.y) + "," + std::to_string(current.x);
                if(filled[name].find(current.dir) == filled[name].npos)
                {
                    filled[name] += current.dir;
                }
                else
                {
                    break;
                }
                switch (input[current.y][current.x])
                {
                case '-':
                    if(current.dir == 'n' || current.dir == 's')
                    {
                        next.dir = 'e';
                        next.x = current.x;
                        next.y = current.y;
                        beams.push(next);    
                        current.dir = 'w';
                    }
                    break;
                case '/':
                    if(current.dir == 'n')
                    {
                        current.dir = 'e';
                    }
                    else if(current.dir == 's')
                    {
                        current.dir = 'w';
                    }
                    else if(current.dir == 'w')
                    {
                        current.dir = 's';
                    }
                    else
                    {
                        current.dir = 'n';
                    }
                    break;
                case '\\':
                    if(current.dir == 'n')
                    {
                        current.dir = 'w';
                    }
                    else if(current.dir == 's')
                    {
                        current.dir = 'e';
                    }
                    else if(current.dir == 'w')
                    {
                        current.dir = 'n';
                    }
                    else
                    {
                        current.dir = 's';
                    }
                    break;
                case '|':
                    if(current.dir == 'e' || current.dir == 'w')
                    {
                        next.dir = 'n';
                        next.x = current.x;
                        next.y = current.y;
                        beams.push(next);    
                        current.dir = 's';
                    }
                    break;
                default:
                    break;
                }
                switch (current.dir)
                {
                case 'n':
                    current.y--;
                    break;
                
                case 's':
                    current.y++;
                    break;
                case 'w':
                    current.x--;
                    break;
                case 'e':
                    current.x++;
                    break;
                }
            }
        }
        if(max < filled.size())
        {
            max = filled.size();
        }
    }
    //std::cout << "The max is: " << max << std::endl;
}