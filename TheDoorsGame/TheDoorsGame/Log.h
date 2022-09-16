#pragma once
#include <iostream>
extern std::wostream wcout;
template<typename F, typename S = F, typename T = S>
void Log(F _first, S _second = "", T _third = "")
{
	std::wcout << _first << _second << _third << "\n";
}