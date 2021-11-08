#include "party.hpp"


Party::Party(int people)
{
    // Init party values
    time = 0;

    // Fill up RoomA with people
    for (int i = 0; i < people; i++)
    {
        RoomA.push_back(Person());
    }
}

void Party::step()
{
    time++;
    //Get two different random people in room A
    int firstInd = getRand(0, RoomA.size() - 1);
    int secondInd = -1;
    do
    {
        secondInd = getRand(0, RoomA.size() - 1);
    } while (firstInd == secondInd);

    Person first = RoomA[firstInd];
    Person second = RoomA[secondInd];

    //Check if they have the same interest
    std::cout << "Person " << first.getId() << " is greeting Person " << second.getId() << std::endl;

    if (first.getInterest() == second.getInterest())
    {
        std::cout << "They clicked! They both like " << second.getInterest() << std::endl;
        // If yes -> move both to room b
        RoomB.push_back(first);
        RoomB.push_back(second);
        if (firstInd > secondInd)
        {
            RoomA.erase(RoomA.begin() + firstInd);
            RoomA.erase(RoomA.begin() + secondInd);
        }
        else
        {
            RoomA.erase(RoomA.begin() + secondInd);
            RoomA.erase(RoomA.begin() + firstInd);
        }
    }
    else
    {
        // If no -> do nothing
        std::cout << "Not a match: Person " << first.getId() << " likes " << first.getInterest() << " and ";
        std::cout << "Person " << second.getId() << " likes " << second.getInterest() << std::endl;
    }

    std::cout << std::endl;
}



bool Party::finished()
{
    bool isFinished = false;
    std::vector<Person> tempA = RoomA;

    // If Room A has one or less people, party is over
    if (RoomA.size() < 2)
    {
        isFinished = true;
    }
    else
    {
        // If no more pairs, party is over
        std::sort(tempA.begin(), tempA.end());

        if (tempA.end() == std::adjacent_find(tempA.begin(), tempA.end()))
        {
            isFinished = true;
        }
    }

    return isFinished;
}

void Party::printStatus()
{
    std::cout << "The time is " << time << std::endl;
    std::cout << "Room A contains: " << std::endl;
    if (RoomA.size() > 0)
    {
        for (int i = 0; i < RoomA.size(); i++)
        {
            std::cout << "Person " << std::to_string(RoomA[i].getId()) << " with interest " << RoomA[i].getInterest() << std::endl;
        }
    }
    else
    {
        std::cout << "Empty" << std::endl;
    }

    std::cout << "Room B contains: " << std::endl;
    if (RoomB.size() > 0)
    {
        for (int i = 0; i < RoomB.size(); i++)
        {
            std::cout << "Person " << std::to_string(RoomB[i].getId()) << " with interest " << RoomB[i].getInterest() << std::endl;
        }
    }
    else
    {
        std::cout << "Empty" << std::endl;
    }
    std::cout << std::endl;
}