// laba5.cpp : Операторы переходов и циклов
//

#include "pch.h"
#include <iostream>


 /*if - оператор условного перехода 

 if (лог_усл)
 {
 //код, выполняемый если (лог_усл == true)
 }
 else
 {
 //код, выполняемый в противном случае
 }
 Примеры:
 if(a > b){...   ;
 bool c = ...;
 bool d = ...;
 if (c && d) {...
 */
	void print_array(char arr[10])
	{
		for (int iter = 0; iter < 10; iter++)
		{
			std::cout << arr[iter];
		}
		std::cout << std::endl;
	}
	int* input_array()
	{
		int arr[10] = { 0 };
		for (int iter = 0; iter < 10; iter++)
		{
			std::cin >> arr[iter];
		}
		return arr;
	}
	int main()
	{
	
	char str[10] = { 'a','b','c','d','e','f','g','h','i','z' };
	int key = 1;
	for (int iter = 0; iter < 10; iter++)
	{
		std::cout << str[iter];
	}
	std::cout << std::endl;

	int iter = 0;
	while (true)
	{
		std::cout << iter;
		iter++;
		if (iter = 10)
		{
			break;
		}
	}
	//шифрование методом Цезаря
	int code = 0;
	for (int iter = 0; iter < 10; iter++)
	{
		code = str[iter] + key;
		if (code > 122)
		{
			code = code - 26;
		}
		str[iter] = char(code);
	}
	print_array(str);
}
