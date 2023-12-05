#include "../inc/day4.hpp"
#include "../inc/macros.hpp"

#include <queue>
#include <algorithm>

using namespace DayFour;

void DayFour::part1()
{
    OPEN("data/day4.txt");
    std::string line;
    int sum = 0;
    while(getline(file, line))
    {
        int win = 1;
        line = line.erase(0,line.find(':')+1);
        std::vector<int> winning = getNumbers(line);
        std::vector<int> ticket = getNumbers(line.erase(0,line.find('|')+1).append(" |"));
        for(int i=0; i<ticket.size(); i++)
        {
            for(int j=0;j<winning.size(); j++)
            {
                if(ticket[i] == winning[j])
                {
                    win *= 2;
                    break;
                }
            }
        }
        sum += win/2;
    }
    std::cout << "The sum is: " << sum << std::endl;
}


void DayFour::part2()
{
    int sum = 0;
    std::vector<int> wins;
    std::vector<int> tickets;
    OPEN("data/day4.txt");
    std::string line;
    tickets.push_back(1);
    for(int x=0; getline(file,line); x++)
    {
        if(tickets.size()-1 < x)
        {
            tickets.push_back(1);
        }
        int win = 0;
        line = line.erase(0,line.find(':')+1);
        std::vector<int> winning = getNumbers(line);
        std::vector<int> ticket = getNumbers(line.erase(0,line.find('|')+1).append(" |"));
        for(int i=0; i<ticket.size(); i++)
        {
            for(int j=0;j<winning.size(); j++)
            {
                if(ticket[i] == winning[j])
                {
                    ++win;
                    break;
                }
            }
        }
        wins.push_back(win);
        sum += tickets[x];
        for(int i=1; i<=win; i++)
        {
            if(tickets.size()-1 < x+i){
                tickets.push_back(1);
            }
            tickets[x+i] += tickets[x];
        }
    }
    std::cout << "The sum is: " << sum << std::endl;
}

std::vector<int> DayFour::getNumbers(std::string line)
{
    int temp = 0;
    std::vector<int> numbers;
    for(int i=1;line[i]!= '|';i++)
    {
        if(isdigit(line[i]))
        {
            temp = temp*10 + (int)line[i]-48;
        }
        else if(temp != 0)
        {
            numbers.push_back(temp);
            temp = 0;
        }
    }
    return numbers;
}