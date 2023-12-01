#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

int main()
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