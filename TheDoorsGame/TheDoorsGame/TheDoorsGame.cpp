
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <algorithm>
#include <random>
#include <Windows.h>

#include "Log.h"
#include "CheckInputIndex.h"
#include "Door.h"
#include "RandomGenerator.h"
#include "Pics.h"

enum InputIndex 
{
  I = 73, i = 105, R = 82, r = 114, P = 80, p = 112, C = 67, c = 99,
  One = 49, Two = 50, Three = 51, Four = 52, Five = 53, Six = 54, Seven = 55, Eight = 56, Nine = 57
};

inline bool GetInput(int upCaseVal, int lowCaseVal)
{
        wchar_t input;
        std::wcin >> input;

        if (input == upCaseVal || input == lowCaseVal)
            return true;
        else return false;
}

#define DoorsRef std::vector<Door>&

void SetDoorsIndexes(DoorsRef doors)
{
    for (int i = 1; i < doors.size(); i++) //guarantee that one door will be empty
            doors[i].SetDoorIndex(GeneratePosRandInt(0, StateCount));
}

inline void RandomlyShufle(DoorsRef doors)
{
    auto rd = std::random_device{};
    auto rng = std::default_random_engine{ rd() };
    std::shuffle(std::begin(doors), std::end(doors), rng);
}

#define ZERO 0;
static int coinsCount = ZERO;

void OpenTheDoor(Door& door);

void Play()
{
    LockLog();

    unsigned int doorCount = GeneratePosRandInt();

    #define OUT_RANGE -1
    int userDoorIndex = OUT_RANGE;

    std::vector<Door> doors(doorCount);
    SetDoorsIndexes(doors);
    RandomlyShufle(doors);

    Log("U have ", doorCount, " doors");
    Log("and ", coinsCount, " coins");
    Log("Please choose the door");

INPUT:
    std::cin >> userDoorIndex;

    int inputKey[9] = { One, Two, Three, Four, Five, Six, Seven, Eight, Nine };

    for (int i = 0; i < doorCount; i++)
    {
        if (userDoorIndex = inputKey[i])
            OpenTheDoor(doors[i]);
        else
        {
            Log("Enter the valid input please");
            goto INPUT;
        }
    }

    std::cin.get();
}

inline void Replay()
{
    coinsCount = ZERO;
    Play();
}

int main(void);

void OpenTheDoor(Door& door)
{
    switch (door.GetDoorIndex())
    {
    case Empty:
        Log("This door is empty, not bad, not good");
        Play();
        break;
    case Ghost:
        GhostLog();
        Log("Booooo, you are in a trouble");
        Replay();
        break;
    case Coin:
        CoinLog();
        Log("Fortuna mama mia, u have found a coin");
        coinsCount++;

        #define MaxRounds 10
        if (coinsCount == MaxRounds)
        {
            Log("U win");
            main();
        }
        else  Play();       
        break;
    default:
        break;
    }
}

int main(void)
{
    //_setmode(_fileno(stdout), _O_U16TEXT);
    #pragma region StartMenu
    Log("Welcome to The Doors. Just choose the door and try your luck");

    Log("Earn 10 coins to win, avoid ghost and don`t be upset by an empty door");

    Log("Press 'I' to get navigation info");

    if (GetInput(I, i)) Log("Press: P -> play"); 

    if (GetInput(P, p)) Play();
    else Log("Invalid input");
    #pragma endregion
}



