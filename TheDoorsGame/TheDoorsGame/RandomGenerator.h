#pragma once

#include <random>

#define defLowB 0
#define defUpB 25

inline int GeneratePosRandInt(int lowBound = defLowB, int upBound = defUpB)
{
	std::random_device rseed;
	std::mt19937 rgen(rseed());
	std::uniform_int_distribution<int> idist(lowBound, upBound);

	return rand();
}




