#include "person.hpp"

int Person::idCounter = 0;

Person::Person()
{
    id = idCounter++;
    interest = availInterests[getRand(0, availInterests.size() - 1)];
}
std::string Person::getInterest()
{
    return interest;
}
int Person::getId()
{
    return id;
}