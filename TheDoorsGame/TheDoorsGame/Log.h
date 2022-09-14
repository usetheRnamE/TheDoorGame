#pragma once
#include <iostream>

#include <optional>
template<typename F, typename S = F, typename T = S>
void Log(F _first, S _second = NULL, T _third = NULL)
{
	std::cout << _first << _second << _third << "\n";
}