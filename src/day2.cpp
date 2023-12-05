#include "../inc/day2.hpp"
#include "../inc/macros.hpp"

#include <string>
#include <cmath>


void DayTwo::part1(){
    OPEN("data/day2.txt");
    std::string line;
    int sum = 0;
    std::string colours[] = {"red", "green", "blue"};
    int numbers[] = {12, 13, 14};
    while(getline(file, line))
    {
        bool possible = true;
        for(int i=0; i<(sizeof(colours)/sizeof(*colours)); i++)
        {
            int index = -1;
            while(line.find(colours[i], index+1) != line.npos)
            {
                int nlocation = line.find(colours[i], index+1);
                int amount = 0;
                for(int x=2;(int)line[nlocation-x] != 32 ;x++)
                {
                    amount += ((int)line[nlocation-x] - 48) * std::pow(10,x-2);
                }
                if(amount > numbers[i])
                {
                    possible = false;
                    break;
                }
                index = nlocation; 
            }
            if(!possible)
            {
                break;
            }
        }
        if(possible)
        {
            for(int i=1;(int)line[line.find(':')-i] != 32;i++)
            {
                sum += ((int)line[line.find(':') - i] - 48)*std::pow(10,i-1);
            }
        }
    }
    std::cout << "The sum is: " << sum << std::endl;
}

void DayTwo::part2(){
    OPEN("data/day2.txt");
    std::string line;
    int sum = 0;
    std::string colours[] = {"red", "green", "blue"};
    while(getline(file, line))
    {
        int numbers[] = {0, 0, 0};
        for(int i=0; i<(sizeof(colours)/sizeof(*colours)); i++)
        {
            int index = -1;
            while(line.find(colours[i], index+1) != line.npos)
            {
                int nlocation = line.find(colours[i], index+1);
                int amount = 0;
                for(int x=2;(int)line[nlocation-x] != 32 ;x++)
                {
                    amount += ((int)line[nlocation-x] - 48) * std::pow(10,x-2);
                }
                if(amount > numbers[i])
                {
                    numbers[i] = amount;
                }
                index = nlocation;
            }
        }
        int power = 1;
        for(int i=0; i<(sizeof(numbers)/sizeof(*numbers));i++)
        {
            power *= numbers[i];  
        }
        sum += power;
    }
    std::cout << "The sum is: " << sum << std::endl;
}