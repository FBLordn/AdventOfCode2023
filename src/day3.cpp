#include "../inc/day3.hpp"
#include "../inc/macros.hpp"

#include <algorithm>

using namespace DayThree;

void DayThree::part1()
{
    std::ifstream data ("data.txt");
    if(!data.is_open()){
        std::cout << "error";
        return;
    }
    std::string input[std::count(std::istreambuf_iterator<char>(data), std::istreambuf_iterator<char>(), '\n')+3];
    std::string line;
    int sum = 0;
    OPEN("data.txt")
    for(int l=1; getline(file, line); l++)
    {
        input[l] = "." + line + ".";
    }
    input[0] = std::string(input[1].length(),'.');
    input[sizeof(input)/sizeof(input)-1] = std::string(input[1].length(),'.');

    for(int i=1;i<(sizeof(input)/sizeof(*input)-1);i++)
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
    std::ifstream data ("data.txt");
    if(!data.is_open()){
        std::cout << "error";
        return;
    }
    std::string input[std::count(std::istreambuf_iterator<char>(data), std::istreambuf_iterator<char>(), '\n')+3];
    std::string line;
    int sum = 0;
    OPEN("data.txt")
    for(int l=1; getline(file, line); l++)
    {
        input[l] = "." + line + ".";
    }
    input[0] = std::string(input[1].length(),'.');
    input[sizeof(input)/sizeof(input)-1] = std::string(input[1].length(),'.');

    for(int i=1;i<(sizeof(input)/sizeof(*input)-1);i++)
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