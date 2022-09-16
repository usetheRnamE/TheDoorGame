#pragma once

#include <random>

#define defLowB 0
#define defUpB 9

inline int GeneratePosRandInt(const int lowBound = defLowB, const int upBound = defUpB)
{
	srand(time(NULL));
	return lowBound + rand() / (RAND_MAX / (upBound - lowBound + 1) + 1);
}




