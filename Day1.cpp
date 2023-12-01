#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

int main()
{
    part1();
    part2();
}

int part1()
{
    std::ifstream file ("data.txt");
    if(file.is_open())
    {
        int sum = 0;
        std::string line;
        while(getline(file, line))
        {
            int fdigit = -1;
            int ldigit = -1;
            for(int i=0;i<line.length();i++)
            {
                int f = (int)line.at(i) - 48;
                int l = (int)line.at(line.length()-1-i) - 48;
                if(f <= 9 && fdigit == -1)
                {
                    fdigit = f;
                }
                if(l <= 9 && ldigit == -1)
                {
                    ldigit = l;
                }
                if(l != -1 && f != -1)
                {
                    break;
                }
            }
            sum += fdigit*10 + ldigit;
        }
        std::cout << "The sum is: " << sum << std::endl;
    }
    else
    {
        std::cout << "File not open";
    }
}

int part2()
{
    std::ifstream file ("data.txt");
    if(file.is_open())
    {
        int sum = 0;
        std::string line;
        std::string numbers[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        while(getline(file, line))
        {
            int fdigit = 0;
            int findex = line.length();
            int ldigit = 0;
            int lindex = -1;
            for(int i=0;i<(sizeof(numbers)/sizeof(*numbers));i++)
            {
                int index = line.find(numbers[i]);
                if(index < findex && index != line.npos)
                {
                    findex = index;
                    fdigit = (int)numbers[i%10][0] - 48;
                }
                while(line.find(numbers[i], lindex+1) != line.npos)
                {
                    lindex = line.find(numbers[i], lindex+1);
                    ldigit = (int)numbers[i%10][0] - 48;
                }
            }
            sum += fdigit*10 + ldigit;
        }
        std::cout << "The sum is: " << sum << std::endl;
    }
    else
    {
        std::cout << "File not open";
    }
}