#include "../inc/day1.hpp"
#include "../inc/day2.hpp"
#include "../inc/macros.hpp"

int main()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    TIMER(DayOne::part1, start, end);
    TIMER(DayOne::part2, start, end);
    TIMER(DayTwo::part1, start, end);
    TIMER(DayTwo::part2, start, end);
}