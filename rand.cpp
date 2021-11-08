#include "rand.hpp"

int getRand(int min, int max) //Taken from cppref, simple great pattern
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}