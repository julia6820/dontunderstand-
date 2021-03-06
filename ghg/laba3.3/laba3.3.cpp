//лаба 3. Шейкер сортировка c помощью функции 

#include "pch.h"
#include <iostream>

void sortShaker(int * a);
int main()
{
	int a[10] = { 5,8,75,4,96,21,15,5,6,3 };
	int *ptr_a = &a[0];
	sortShaker(ptr_a);

	for (int i = 0; i < 10; i++)
		std::cout << a[i] << " ";
	return 0;
}


void sortShaker(int * a)
{
	int b = 0;
	for (int j = 0; j < 10 / 2; j++)
	{
		int fb = 0;
		int sb = 9;
		while (fb < sb)
		{
			if (a[fb] > a[fb + 1])
			{
				b = a[fb];
				a[fb] = a[fb + 1];
				a[fb + 1] = b;
			}

			fb++;

			if (a[sb - 1] > a[sb])
			{
				b = a[sb - 1];
				a[sb - 1] = a[sb];
				a[sb] = b;
			}
			sb--;
		}

	}
}
