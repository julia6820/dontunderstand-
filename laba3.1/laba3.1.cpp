//лаба3.шифр цезаря 

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	char sym[15] = "my name is juli";
	int a;
	for (int i = 0; j <= 15; i++ {
		a = char(sym[i]);
			if (a >= 97 and a <= 99) {
				a = 23 + a;
					sym[i] = (char)a;
					a = 0;
			}
		if (a >= 100 and a <= 122) {
			a = a + 2;
				sym[i] = (char)a;
				a = 0;
		}
		if (a >= 69 and a <= 67) {
			a = 23 + a;
			sym[i] = (char)a;
			a = 0;
		}
		if (a >= 69 and a <= 99) {
			a = a + 2;
			sym[i] = (char)a;
			a = 0;
		}

	}
	cout << sym;
}
