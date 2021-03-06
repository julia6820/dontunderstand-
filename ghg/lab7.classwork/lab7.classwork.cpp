// lab7.classwork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
 
using namespace std;

class matrix
{
private:
	int * matr = new int[rows*columns];
	int rows;
	int columns;
	int * res = new int[rows*columns];

public:
	matrix();
	~matrix();

	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	int getElem(int row, int col);
	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}

	bool input();
	void transp();

	void printMat()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				std::cout << matr[i*columns + j] << "\t";
			}
			std::cout << endl;
		}
	};

};


int main()
{
	matrix matrA, matrB;
	matrA.input();
	matrB.input();
	matrA.multMatrix(matrB);
	int p;
}
matrix::matrix() {}
matrix::~matrix() {}

bool matrix::summMatrix(matrix matr2)
{
	if (rows == matr2.getRows() && columns == matr2.getColumns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i*columns + j] += matr2.getElem(i, j);
			}
		}
		printMat();
		return true;
	}
	else {
		return false;
	}
}
void matrix::transp()
{
	int k;
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << matr[j * columns + i] << " ";
		}
		cout << endl;
	}
}
bool matrix::multMatrix(matrix matr2)
{
	if (columns == matr2.getRows())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				int sum = 0;
				for (int p = 0; p < columns; p++)
				{
					sum += matr[i * columns + p] * matr2.getElem(p, j);
				}
				res[i * columns + j] = sum;
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				cout << res[i * columns + j] << " ";
			}
			cout << endl;
		}
		return true;
	}
	else {
		cout << "col1 !=row2";
		return false;
	}
}
int matrix::getElem(int row, int col)
{
	if (row<rows && col<columns && row>-1 && col > -1)
	{
		return matr[row * columns + col];
	}
	else
	{
		std::cout << "ERROR\n";
		return -1;
	}
}
bool matrix::input()
{
	std::cout << "rows=";
	std::cin >> rows;
	if (rows < 1 || rows>10)
	{
		return false;
	}
	std::cout << "columns=";
	std::cin >> columns;
	if (columns < 1 || columns>10)
	{
		return false;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i * columns + j ];
		}
		cout << endl;
	}
	return true;
}