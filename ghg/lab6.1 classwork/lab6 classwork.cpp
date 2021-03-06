// lab6.1 classwork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h" 
#include <iostream>
#include <cstring>

using namespace std;

class matrix
{
private:

	double matr[10][10];
	int rows;
	int columns;
	int res[10][10];

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
				std::cout << matr[i][j] << "\t";
			}
			std::cout << endl;
		}
	};

};
class vector : matrix
{
private:
	int n;
	int vec[10];
public:

	int getn()
	{
		return n;
	}
	int getElem(int n);
	bool enter();
	void pvec(int p)
	{
		for (int i = 0; i < n; i++)
		{
			vec[i] *= p;
			cout << vec[i] << ' ';
		}
	};
	bool multvec(vector vec2);
};
 

int main()
{
	matrix matrA, matrB;
	matrA.input();
	matrB.input();
	matrA.multMatrix(matrB);
	int p;
	
	return 0;
}
matrix::matrix(){}
matrix::~matrix() {}
bool matrix::summMatrix(matrix matr2)
{
	if (rows == matr2.getRows()&& columns == matr2.getColumns()) 
	{ 
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i][j] += matr2.getElem(i, j);
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
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << matr[j][i] << " ";
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
					sum += matr[i][p] * matr2.getElem(p, j);
				}
				res[i][j] = sum;
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				cout << res[i][j] << " ";
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
		return matr[row][col];
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
			std::cout << "matr[" << i << "][" << j << "]=";
			std::cin >> matr[i][j];
		}
		cout << endl;
	}
	return true;
}
void matrix::transp()
{
	for (int i = 0; i <10;i++)
	{
		for (int j = i; j < rows; j++)
		{
			double temporary = matr[j][i];
			matr[j][i] = temporary;
		}
	}
	int temporary = columns;
	columns = rows;
	rows = temporary;
}
int vector::getElem(int n)
{
	if (n < 11 && n > 0)
	{
		return vec[n];
	}
	else
	{
		cout << "error";
		return -1;
	}
}
bool vector::enter()
{
	cout << "n=";
	cin >> n;
	if (n < 1 || n > 10)
	{
		return false;
	}
	for (int j = 0; j < n; j++)
	{
		cout << "vec[" << j << "]=";
		cin >> vec[j];
	}
	return true;
}

bool vector::multvec(vector vec2)
{
	int scal = 0;
	if (n = vec2.getn())
	{
		for (int i = 0; i < n; i++)
		{
			scal += vec[i] * vec2.getElem(i);
		}
		cout << scal;
	}
	else {
		return false;
	}
}
