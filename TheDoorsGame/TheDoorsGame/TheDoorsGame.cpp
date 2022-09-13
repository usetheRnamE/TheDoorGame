
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>


#include "Log.h"
#include "CheckInputIndex.h"
#include "Door.h"
#include "RandomGenerator.h"
#include "Pics.h"

enum InputIndex 
{
  I = 73, i = 105, R = 82, r = 114, P = 80, p = 112, C = 67, c = 99
};

inline bool GetInput(int upCaseVal, int lowCaseVal)
{
        int input;

        input = _getch();
        putchar(input);
        system("cls");

        if (input == upCaseVal || input == lowCaseVal)
            return true;
        else return false;
}

void Play()
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    LockLog();

    unsigned int doorCount = GeneratePosRandInt();
    
    Log("U have", doorCount, "doors");

    std::vector<Door> doors(doorCount);

    std::cin.get();
}

void Replay()
{

}

void Close()
{

}

int main(void)
{
    #pragma region StartMenu
    Log("Welcome to The Doors. Just choose the door and try your luck");

    Log("Earn 10 coins to win, avoid ghost and don`t be upset by an empty door");

    Log("Press 'I' to get navigation info");
    if (GetInput(I, i))
        Log("Press: P -> play,  R -> replay, C -> close");
    #pragma endregion

    if (GetInput(P, p)) Play();
    else if (GetInput(R, r)) Replay();
    else if (GetInput(C, c)) Close();    
}



