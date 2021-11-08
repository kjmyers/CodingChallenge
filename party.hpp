#ifndef PARTY_H
#define PARTY_H

#include <iostream>
#include "person.hpp"


class Party
{
private:
    std::vector<Person> RoomA;
    std::vector<Person> RoomB;
    int time;

public:
    Party(int people);
    void printStatus();
    void step();
    bool finished();
};

#endif 