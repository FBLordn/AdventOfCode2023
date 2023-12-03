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
    std::string input[std::count(std::istreambuf_iterator<char>(data), std::istreambuf_iterator<char>(), '\n')+1];
    std::string line;
    int sum = 0;
    OPEN("data.txt")
    for(int l = 0;getline(file, line);l++)
    {
        input[l] = line;
    }
    
    for(int i=0;i<(sizeof(input)/sizeof(*input));i++)
    {
        for(int x=0;x<input[i].length();x++)
        {
            if(input[i][x] != '.' && !isdigit(input[i][x]))
            {
                if(i>0)
                {
                    sum += checkLine(input[i-1], x);
                }
                if(x>0)
                {
                    if(isdigit(input[i][x-1]))
                    {
                        sum += getNumber(input[i], x-1);
                    }
                }
                if(x<input[i].length()-1){
                    if(isdigit(input[i][x+1]))
                    {
                        sum += getNumber(input[i], x+1);
                    }
                }
                if(i<sizeof(input)/sizeof(*input))
                {
                    sum += checkLine(input[i+1], x);
                }
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
    std::string input[std::count(std::istreambuf_iterator<char>(data), std::istreambuf_iterator<char>(), '\n')+1];
    std::string line;
    int sum = 0;
    OPEN("data.txt")
    for(int l = 0;getline(file, line);l++)
    {
        input[l] = line;
    }
    for(int i=0;i<(sizeof(input)/sizeof(*input));i++)
    {
        for(int x=0;x<input[i].length();x++)
        {
            int count = 0;
            int number = 1;
            if(input[i][x] == '*')
            {
                if(i>0)
                {
                    if(x>0){
                        if(isdigit(input[i-1][x-1]))
                        {
                            ++count;
                            number *= getNumber(input[i-1],x-1);
                        }
                    }
                    if(!isdigit(input[i-1][x-1]) && isdigit(input[i-1][x]))
                    {
                        ++count;
                        number *= getNumber(input[i-1], x);
                    }
                    if(x<input[i-1].length()-1){
                        if(!isdigit(input[i-1][x]) && isdigit(input[i-1][x+1]))
                        {
                            ++count;
                            number *= getNumber(input[i-1], x+1);
                        }
                    }
                }
                if(x>0)
                {
                    if(isdigit(input[i][x-1]))
                    {
                        ++count;
                        number *= getNumber(input[i], x-1);
                    }
                }
                if(x<input[i].length()-1){
                    if(isdigit(input[i][x+1]))
                    {
                        ++count;
                        number *= getNumber(input[i], x+1);
                    }
                }
                if(i<sizeof(input)/sizeof(*input))
                {
                    if(x>0){
                        if(isdigit(input[i+1][x-1]))
                        {
                            ++count;
                            number *= getNumber(input[i+1],x-1);
                        }
                    }
                    if(!isdigit(input[i+1][x-1]) && isdigit(input[i+1][x]))
                    {
                        ++count;
                        number *= getNumber(input[i+1], x);
                    }
                    if(x<input[i+1].length()-1){
                        if(!isdigit(input[i+1][x]) && isdigit(input[i+1][x+1]))
                        {
                            ++count;
                            number *= getNumber(input[i+1], x+1);
                        }
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

int DayThree::getNumber(std::string line, int index)
{
    int nindex = 0;
    int number = 0;

    for(int i=index;(i>=0);i--){
        if(isdigit(line[i]))
        {
            nindex = i;
        }
        else
        {
            break;
        }
    }
    for(int i = nindex; (isdigit(line[i]) && i<line.length());i++)
    {
        number = number*10 + (int)line[i]-48;
    }
    return number;
}

int DayThree::checkLine(std::string line, int x){
    int sum = 0;
    if(x>0){
        if(isdigit(line[x-1]))
        {
            sum += getNumber(line,x-1);
        }
    }
    if(!isdigit(line[x-1]) && isdigit(line[x]))
    {
        sum += getNumber(line, x);
    }
    if(x<line.length()-1){
        if(!isdigit(line[x]) && isdigit(line[x+1]))
        {
            sum += getNumber(line, x+1);
        }
    }
    return sum;
}