#include "../inc/day4.hpp"
#include "../inc/macros.hpp"

#include <queue>
#include <algorithm>

using namespace DayFour;

void DayFour::part1()
{
    OPEN("data.txt");
    std::string line;
    int sum = 0;
    while(getline(file, line))
    {
        int win = 1;
        line = line.erase(0,line.find(':')+1);
        int winning[(line.find('|')-1)/3];
        int temp = 0;
        for(int i=1;line[i]!= '|';i++)
        {
            if(isdigit(line[i]))
            {
                temp = temp*10 + (int)line[i]-48;
            }
            else if(temp != 0)
            {
                winning[(i-1)/3] = temp;
                temp = 0;
            }
        }
        line = line.erase(0,line.find('|')+1);
        line.append(" ");
        int ticket[(line.length())/3];
        for(int i=0;i<line.length();i++)
        {
            if(isdigit(line[i]))
            {
                temp = temp*10 + (int)line[i]-48;
            }
            else if(temp != 0)
            {
                ticket[(i-1)/3] = temp;
                temp = 0;
            }
        }
        for(int i=0; i<sizeof(ticket)/sizeof(*ticket); i++)
        {
            for(int j=0;j<sizeof(winning)/sizeof(*winning); j++)
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

int* DayFour::getNumbers(std::string line)
{
    int numbers[(line.find('|')-2)/3+1];
    int temp = 0;
    for(int i=1;line[i]!= '|';i++)
    {
        if(isdigit(line[i]))
        {
            temp = temp*10 + (int)line[i]-48;
        }
        else
        {
            numbers[(i-1)/3] = temp;
        }
    }
    numbers[sizeof(numbers)/sizeof(*numbers)] = -1;
    return numbers;
}


void DayFour::part2()
{
    std::ifstream data ("data.txt");
    if(!data.is_open()){
        std::cout << "error";
        return;
    }
    std::string input[std::count(std::istreambuf_iterator<char>(data), std::istreambuf_iterator<char>(), '\n')+1];
    OPEN("data.txt");
    std::string line;
    for(int l=0; getline(file, line); l++)
    {
        input[l] = line;
    }
    int arrlength = sizeof(input)/sizeof(*input);
    int wins[arrlength];
    std::fill_n(wins, arrlength, -1);
    std::queue<int> tickets;
    for(int i=0; i<arrlength-1; i++)
    {
        tickets.push(i);
    }
    int sum = arrlength-1;
    while(!tickets.empty())
    {
        int x = tickets.front();
        tickets.pop();
        if(wins[x] != -1)
        {
            sum += wins[x];
            for(int i=1; i<=wins[x];i++)
            {
                tickets.push(x+i);
            }
            continue;
        }
        std::string line = input[x]; 
        int win = 0;
        line = line.erase(0,line.find(':')+1);
        int winning[(line.find('|')-1)/3];
        int temp = 0;
        for(int i=1;line[i]!= '|';i++)
        {
            if(isdigit(line[i]))
            {
                temp = temp*10 + (int)line[i]-48;
            }
            else if(temp != 0)
            {
                winning[(i-1)/3] = temp;
                temp = 0;
            }
        }
        line = line.erase(0,line.find('|')+1);
        line.append(" ");
        int ticket[(line.length())/3];
        for(int i=0;i<line.length();i++)
        {
            if(isdigit(line[i]))
            {
                temp = temp*10 + (int)line[i]-48;
            }
            else if(temp != 0)
            {
                ticket[(i-1)/3] = temp;
                temp = 0;
            }
        }
        for(int i=0; i<sizeof(ticket)/sizeof(*ticket); i++)
        {
            for(int j=0;j<sizeof(winning)/sizeof(*winning); j++)
            {
                if(ticket[i] == winning[j])
                {
                    win++;
                    break;
                }
            }
        }
        sum += win;
        wins[x] = win;
        for(int i=1; i<=win;i++)
        {
            tickets.push(x+i);
        }
    }
    std::cout << "The sum is: " << sum << std::endl;
}