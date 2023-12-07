#include "../inc/day7.hpp"
#include "../inc/macros.hpp"

#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace DaySeven;

void DaySeven::part1()
{
    unsigned int sum = 0;
    std::vector<hand> hands;
    OPEN("data/day7.txt");
    std::string line;
    while(getline(file, line))
    {
        hand current;
        std::stringstream ss (line);
        getline(ss, current.cards, ' ');
        getline(ss, line, ' ');
        current.bid = std::stoi(line);
        current.worth = getWorth1(current.cards);
        hands.push_back(current);
    }
    std::sort(hands.begin(), hands.end(), compareLength);
    for(int i=0; i<hands.size(); i++)
    {
        sum += hands[i].bid * (i+1);
    }
    //std::cout << "The sum is: " << sum << std::endl;
}

bool DaySeven::compareLength(const hand& a, const hand& b)
{
    return a.worth < b.worth;
}

unsigned long DaySeven::getWorth1(std::string cards)
{
    unsigned long cValue = 0;
    std::vector<int> counts(13, 0);
    int card = 0;
    char c;
    for(int i=0; i<cards.size(); i++)
    {
        int temp;
        c = cards[i];
        if(isdigit(c))
        {
            card = (int)c-50;
        }
        else
        {
            card = conversion1[c];
        }
        cValue = cValue * 100 + card;
        counts[card] = counts[card] * 2 + 1;
    }
    cValue = std::accumulate(counts.begin(), counts.end(), 0) * std::pow(100,cards.size()) + cValue;
    return cValue;
}

unsigned long DaySeven::getWorth2(std::string cards)
{
    int maxIndex = 0;
    unsigned long cValue = 0;
    std::vector<int> counts(12, 0);
    int jCount = 0;
    int card = 0;
    char c;
    for(int i=0; i<cards.size(); i++)
    {
        c = cards[i];
        if(isdigit(c))
        {
            card = (int)c-48;
        }
        else
        {
            card = conversion2[c];
        }
        cValue = cValue * 100 + card;
        if(card != 1){
            counts[card-2] = counts[card-2] * 2 + 1;
            if(counts[card-2] > counts[maxIndex])
            {
                maxIndex = card-2;
            }
        }
        else{
            jCount++;
        }
    }
    if(jCount > 0)
    {
        for(jCount; jCount > 0; jCount--)
        {
            counts[maxIndex] = counts[maxIndex] * 2 + 1;
        }
    }
    cValue = std::accumulate(counts.begin(), counts.end(), 0) * std::pow(100,cards.size()) + cValue;
    return cValue;
}

void DaySeven::part2()
{
    unsigned int sum = 0;
    std::vector<hand> hands;
    OPEN("data/day7.txt");
    std::string line;
    while(getline(file, line))
    {
        hand current;
        std::stringstream ss (line);
        getline(ss, current.cards, ' ');
        getline(ss, line, ' ');
        current.bid = std::stoi(line);
        current.worth = getWorth2(current.cards);
        hands.push_back(current);
    }
    std::sort(hands.begin(), hands.end(), compareLength);
    for(int i=0; i<hands.size(); i++)
    {
        sum += hands[i].bid * (i+1);
    }
    //std::cout << "The sum is: " << sum << std::endl;
}