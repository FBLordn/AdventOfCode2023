#include "../inc/day1.hpp"
#include "../inc/day2.hpp"
#include "../inc/day3.hpp"
#include "../inc/day4.hpp"
#include "../inc/day5.hpp"
#include "../inc/macros.hpp"
#include "../inc/day6.hpp"

int main()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    //std::cout << "Day 1: " << std::endl;
    //TIMER(DayOne::part1, start, end);
    //TIMER(DayOne::part2, start, end);
    //std::cout << "Day 2: " << std::endl;
    //TIMER(DayTwo::part1, start, end);
    //TIMER(DayTwo::part2, start, end);
    //std::cout << "Day 3: " << std::endl;
    //TIMER(DayThree::part1, start, end);
    //TIMER(DayThree::part2, start, end);
    //std::cout << "Day 4: " << std::endl;
    //TIMER(DayFour::part1, start, end);
    //TIMER(DayFour::part2, start, end);
    //DayFive::part1();
    //DayFive::part2();
    TIMER(DaySix::part1, start, end);
    TIMER(DaySix::part2, start, end);
}