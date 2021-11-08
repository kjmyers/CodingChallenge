#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "rand.hpp"

class Person
{
private:
    std::vector<std::string> availInterests = {"epidemiology", "biostatistics", "clinical research", "health policy"};
    static int idCounter;
    int id;
    std::string interest;

public:
    Person();
    std::string getInterest();
    int getId();
    bool operator==(const Person &person) const { return interest == person.interest; };
    bool operator>(const Person &person) const { return interest > person.interest; };
    bool operator<(const Person &person) const { return interest < person.interest; };
};

#endif 