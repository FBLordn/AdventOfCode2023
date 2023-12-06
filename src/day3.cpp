#include "../inc/day3.hpp"
#include "../inc/macros.hpp"

#include <algorithm>
#include <vector>

using namespace DayThree;

void DayThree::part1()
{
    std::vector<std::string> input;
    std::string line;
    int sum = 0;
    OPEN("data/day3.txt")
    input.push_back("");
    while(getline(file, line))
    {
        input.push_back("." + line + ".");
    }
    input[0] = std::string(input[1].length(),'.');
    input.push_back(std::string(input[1].length(),'.'));

    for(int i=1;i<(input.size()-1);i++)
    {
        for(int x=1;x<input[i].length()-1;x++)
        {
            if(input[i][x] != '.' && !isdigit(input[i][x]))
            {
                sum += checkLine(input[i-1], x);
                sum += getMiddleNumber(input[i], x-1);
                sum += getMiddleNumber(input[i], x+1);
                sum += checkLine(input[i+1], x);
            }
        }
    }
    std::cout << "The sum is: " << sum << std::endl;
}

void DayThree::part2()
{
    std::vector<std::string> input;
    std::string line;
    int sum = 0;
    OPEN("data/day3.txt")
    input.push_back("");
    while(getline(file, line))
    {
        input.push_back("." + line + ".");
    }
    input[0] = std::string(input[1].length(),'.');
    input.push_back(std::string(input[1].length(),'.'));
    for(int i=1;i<(input.size()-1);i++)
    {
        for(int x=1;x<input[i].length()-1;x++)
        {
            int count = 0;
            int number = 1;
            if(input[i][x] == '*')
            {
                if(isdigit(input[i-1][x]))
                {
                    ++count;
                    number *= getMiddleNumber(input[i-1], x);
                }
                else
                {
                    if(isdigit(input[i-1][x-1]))
                    {
                        ++count;
                        number *= getMiddleNumber(input[i-1],x-1);
                    }
                    if(isdigit(input[i-1][x+1]))
                    {
                        ++count;
                        number *= getMiddleNumber(input[i-1], x+1);
                    }
                }
                if(isdigit(input[i][x-1]))
                {
                    ++count;
                    number *= getMiddleNumber(input[i], x-1);
                }
                if(isdigit(input[i][x+1]))
                {
                    ++count;
                    number *= getMiddleNumber(input[i], x+1);
                }
                if(isdigit(input[i+1][x]))
                {
                    ++count;
                    number *= getMiddleNumber(input[i+1], x);
                }
                else{
                    if(isdigit(input[i+1][x-1]))
                    {
                        ++count;
                        number *= getMiddleNumber(input[i+1],x-1);
                    }
                    if(isdigit(input[i+1][x+1]))
                    {
                        ++count;
                        number *= getMiddleNumber(input[i+1], x+1);
                    }
                }
                if(count == 2)
                {
                    sum += number;
                }
            }
        }
    }
    std::cout << "The sum is: " << sum << std::endl;
}

int DayThree::getMiddleNumber(std::string line, int index)
{
    int nindex = index;
    int number = 0;
    for(int i=index; isdigit(line[i]); i--){
        nindex = i;
    }
    for(int i=nindex; isdigit(line[i]); i++)
    {
        number = number*10 + (int)line[i]-48;
    }
    return number;
}

int DayThree::checkLine(std::string line, int x){
    int sum = 0;
    if(isdigit(line[x]))
    {
        sum += getMiddleNumber(line, x);
    }
    else{
        if(isdigit(line[x-1]))
        {
            sum += getMiddleNumber(line,x-1);
        }
        if(isdigit(line[x+1]))
        {
            sum += getMiddleNumber(line, x+1);
        }
    }
    return sum;
}