﻿#pragma once

#include<iostream>

enum DoorState 
{
   Empty, Ghost, Coin, StateCount
};

class Door
{
private:
	int doorIndex = Empty;

public:
	void SetDoorIndex(const int& index);
	int GetDoorIndex();
};

