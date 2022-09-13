#pragma once
#include <iostream>

#include <optional>
template<typename S, typename I, typename T>
void Log(S _first, const std::optional<I> _second = std::nullopt, const std::optional<T> _third = std::nullopt)
{
	std::cout << _first << _second << _third << "\n";
}