//лаба3.шифр цезаря 

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	char s[15];
	gets_s(s);
	for (int i = 0; i < 14; i++)
	{
		if (s[i] < 120 && s[i] != 32) s[i] = s[i] + 3; 
		else { if (s[i] >= 120) s[i] = s[i] - 23; }
	}
	std::cout << s;
}