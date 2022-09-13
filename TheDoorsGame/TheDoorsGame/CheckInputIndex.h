#pragma once
#include <iostream>
//#include <conio.h>
#include <stdio.h>

void GetInputIndex(void)
{
	int input;
	// Get input:
	input = _getch();
	putchar(input);
	system("cls");
	// Display value of key
	printf("Key Value: %d", input);
}