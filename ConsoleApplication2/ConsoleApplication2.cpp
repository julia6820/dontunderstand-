//лаба3.шифр цезаря 

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	char string[15]; 
	gets_s(string);
	for (int i = 0; i < 14; i++)
	{
		if (string[i] < 120 && string[i] != 32) string[i] = string[i] + 3; 
		else { if (string[i] >= 120) string[i] = string[i] - 23; }
	}
	std::cout << string;
}