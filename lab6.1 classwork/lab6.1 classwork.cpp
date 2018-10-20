// lab6.1 classwork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std; 

class matrix
{
private:
	double matr[10][10];
	int rows;
	int columns;

public:
	matrix();
	~matrix();

	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	double getElem(int row, int col);
	bool input();
	bool transp();
	void print();

	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
};
class vector : matrix
{
private:
	int n;
	double vec[10];
public:
	double scalmultVector(vector vec2);
	double getElem(int n);
	void vecMult(double p);
};


int main()
{
	matrix matrA;
	matrA.input();
	matrA.transp();
	matrA.print();
}
matrix::matrix(){}
matrix::~matrix() {}
bool matrix::summMatrix(matrix matr2)
{
	if ((columns == matr2.getColumns()) && (rows == matr2.getRows()))
	{ 
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				matr[i][j] += matr2.getElem(i, j);
			}
		}
		return true;
	}
	else {
		return false;
	}
}
bool matrix::multMatrix(matrix matr2)
{
	double matr3[10][10];
	if (rows == matr2.getColumns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				int sum = 0;
				for (int p = 0; p < rows; p++)
				{
					sum += matr[i][p] * matr2.getElem(p, j);
				}
				matr3[i][j] = sum;
			}
		}
		columns = rows;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i][j] = matr3[i][j];
			}
		}
		return true;
	}
	else {
		return false;
	}
}
double matrix::getElem(int row, int col)
{
	if (row<rows && col<columns && row>-1 && col > -1)
	{
		return matr[row][col];
	}
	std::cout << "ERROR\n";
	return -1;
}
bool matrix::input()
{
	cout << "rows=";
	cin >> rows;
	if (rows < 1 || rows>10)
	{
		return false;
	}
	cout << "columns=";
	cin >> columns;
	if (columns < 1 || columns>10)
	{
		return false;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "matr[" << i << "][" << j << "]";
			cin >> matr[i][j];
		}
		cout << endl;
	}
	return true;
}
bool matrix::transp()
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << matr[j][i] << " ";
		}
		cout << endl;
	}
}

void matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matr[i][j];
		}
		cout << "\n";
	}
}
double vector::scalmultVector(vector vec2)
{
	if (n == vec2.n)
	{
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += vec[i] * vec2.getElem(i);
		}
		return sum;
	}
	else {
		std::cout << "error";
		return -1;
	}
}
double vector::getElem(int n)
{
	if (n < 10 && n > -1)
	{
		return vec[n];
	}
	return -1;
}
void vector::vecMult(double p)
{
	for (int i = 0; i < n; i++)
	{
		vec[i] *= p;
	}
}