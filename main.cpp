
#include <iostream>
#include <chrono>
#include <thread>

#include <algorithm>

#include "party.hpp"



int main()
{
    Party myParty(9);

    while (!myParty.finished())
    {
        myParty.printStatus();
        myParty.step();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Party is over! Here is the final status:" << std::endl;
    myParty.printStatus();
    return 0;
}